import sqlite3
import subprocess
import os
from statistics import *
from pathlib import Path
from plotly import __version__
from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot
from plotly.offline import init_notebook_mode, iplot
import plotly.graph_objs as go
import plotly.plotly as py
from IPython.display import display, HTML
from numpy import percentile


import pandas as pd

'''
Les algos si dessous sont FORTEMENT inspiré de la documentation
officielle: https://plot.ly/python/
'''

def run_chnabeltier(depart, cycle, nom):
    file = Path(nom)
    if file.is_file():
        os.remove(file)
    
    args = ("./main", str(depart), str(cycle), nom)
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()
    print(popen.stdout.read().decode("utf8"))

def table_to_html(data):
    display(HTML(
        '<table><tr>{}</tr></table>'.format(
            '</tr><tr>'.join(
                '<td>{}</td>'.format('</td><td>'.join(str(_) for _ in row)) for row in data)
            )
    ))


class vogel:
    def __init__(self, depart = 100, cycle = 100, nomdb = "data.db"):
        init_notebook_mode(connected=True)
        run_chnabeltier(depart,cycle,nomdb)
        sql = sqlite3.connect(nomdb)
        self.sqlite = sql
        self.cursor = sql.cursor()
        

    def _get_deads(self):
        L = []
        for row in self.cursor.execute("SELECT DEAD FROM EVOLUTION ORDER BY DEAD"):
            L.append(row[0])
        return L

    def _get_n_deads(self):
        deads = self._get_deads()
        maxl = max(deads)
        L = [0]*maxl
        print(maxl)
        for i in deads:
            L[i - 1] += 1
        return L

    def draw_death(self):
        y = self._get_n_deads()
        x = list(range(0,len(y) - 1))
        iplot([{"x": x, "y": y}])

    def list_traits(self):
        self.cursor.execute("PRAGMA table_info(EVOLUTION);")
        sql = self.cursor.fetchall()
        L = []
        for i in sql:
            L.append(i[1])
        L.remove("DEAD")
        L.remove("GEN")
        L.remove("ID")
        return L

    def _get_trait(self, trait):
        self.cursor.execute("SELECT "+trait+",GEN FROM EVOLUTION ORDER BY GEN")
        return self.cursor.fetchall()
    
    def _get_trait_alive(self, trait):
        self.cursor.execute("SELECT "+trait+",GEN FROM EVOLUTION WHERE DEAD = 0 ORDER BY GEN")
        return self.cursor.fetchall()

    def couple_trait(self, trait):
        L = self._get_trait(trait)
        Ltr = []
        Lgen = []
        for i in L:
            Ltr.append(i[0])
            Lgen.append(i[1])
        return (Ltr,Lgen)

    def couple_trait_alive(self, trait):
        L = self._get_trait_alive(trait)
        Ltr = []
        Lgen = []
        for i in L:
            Ltr.append(i[0])
            Lgen.append(i[1])
        return (Ltr,Lgen)

    def list_by_gen(self,L):
        maxL = max(L[1])
        new = [[] for i in range((maxL+1))]
        for i in range(len(L[1])):
            n = L[1][i]
            new[n].append(L[0][i])
        
        for i in range(len(new)):
            print(len(new[i]))
        return new

    def simple_stat(self):
        data = [["trait", "moyenne", "equart-type"]]
        traits = self.list_traits()
        for tr in traits:
            L = self.couple_trait_alive(tr)
            data_tr = [tr]
            data_tr.append(mean(L[0]))
            data_tr.append(stdev(L[0]))
            data.append(data_tr)
        table_to_html(data)
    
    def draw_moyenne_trait(self,trait):
        L = self.list_by_gen(self.couple_trait(trait))
        print(str(L[0][0]) + " " + str(L[1][0]))
        moy = [0]*len(L)
        minl = [0]*len(L)
        maxl = [0]*len(L)
        equart = [0]*len(L)
        for i in range(len(L)):
            moy[i] = mean(L[i])
            minl[i] = percentile(L[i], 33) #min(L[i])
            maxl[i] = percentile(L[i], 66) #max(L[i])
            equart[i] = stdev(L[i])
        list_x = list(range(len(L)-1))
        y = maxl

        trace0 = go.Scatter(
            x = list_x,
            y = minl,
            mode = 'lines',
            name = 'min'
        )

        trace1 = go.Scatter(
            x = list_x,
            y = moy,
            mode = 'lines',
            name = 'moyenne'
        )

        trace2 = go.Scatter(
            x = list_x,
            y = maxl,
            mode = 'lines',
            name = 'max'
        )

        trace3 = go.Scatter(
            x = list_x,
            y = equart,
            mode = 'lines',
            name = 'equart type'
        )
        iplot([trace0,trace1,trace2,trace3])
def test_plot():
    iplot([{"x": [1, 2, 3], "y": [3, 1, 6]}])

