from queue import *
import sqlite3
import subprocess
import os
from statistics import *
from pathlib import Path
from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot
from plotly.offline import init_notebook_mode, iplot
import plotly.graph_objs as go
import plotly.plotly as py
from IPython.display import display, HTML
from graphviz import Digraph
from numpy import percentile

'''
Les algos si dessous sont FORTEMENT inspiré de la documentation
officielle: https://plot.ly/python/
'''

# classe décrivant un environnement
class env:
    temp = 0
    hum = 0
    eau = 0
    car = 0

    def __init__(self,temp, hum, eau, car):
        self.temp = temp % 100
        self.hum = hum % 100
        self.car = car % 100
        self.eau = eau % 100

# classe décrivant un individu
class ind:
    poils = 0
    palmes = 0
    herbi = 0
    carni = 0

    def __init__(self,poils, palmes, herbi, carni):
        self.poils = poils % 100
        self.palmes = palmes % 100
        self.herbi = herbi % 100
        self.carni = carni % 100

'''
classe faisant appel au fichier compilé
depart: nombre d'individu au départ
cycle: nombre de cycle
nom: nom de la base de donnée
env: environnement
ind: individu type de départ (facultatif)
'''
def run_chnabeltier(depart, cycle, nom, env, ind = None):
    file = Path(nom)
    if file.is_file():
        os.remove(file)
    args = None
    if(ind == None):
        args = ("./main", str(depart), str(cycle), nom, str(env.temp), str(env.hum), str(env.eau), str(env.car))
    else:
        args = ("./main", str(depart), str(cycle), nom, str(env.temp), str(env.hum), str(env.eau), str(env.car), str(ind.poils), str(ind.palmes), str(ind.herbi), str(ind.carni))
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()
    print(popen.stdout.read().decode("utf8"))

# affiche un tableau en html
def table_to_html(data):
    display(HTML(
        '<table><tr>{}</tr></table>'.format(
            '</tr><tr>'.join(
                '<td>{}</td>'.format('</td><td>'.join(str(_) for _ in row)) for row in data)
            )
    ))


# classe décrivant une simulation
class vogel:
    def __init__(self, env ,ind = None, depart = 100, cycle = 100, nomdb = "data.db"):
        init_notebook_mode(connected=True)
        run_chnabeltier(depart,cycle,nomdb, env, ind)
        sql = sqlite3.connect(nomdb)
        self.sqlite = sql
        self.cursor = sql.cursor()
        self.cycle = cycle
    
    def _get_parents_ind(self,i):
        self.cursor.execute("SELECT PAR1,PAR2 FROM EVOLUTION WHERE ID = "+str(i))
        res  = self.cursor.fetchall()
        if res[0][0] == -1:
            return None
        else:
            return res[0]

    def _get_trait_ind(self,i, trait):
        self.cursor.execute("SELECT "+trait+" FROM EVOLUTION WHERE ID = "+str(i))
        res = res = self.cursor.fetchall()
        return res[0][0]


    # retourne tableau d'individus mort triés par date de mort
    def _get_deads(self):
        L = []
        for row in self.cursor.execute("SELECT DEAD FROM EVOLUTION ORDER BY DEAD"):
            L.append(row[0])
        return L

    # retourne tableau avec le nombre de mort par génération
    def _get_n_deads(self):
        deads = self._get_deads()
        maxl = max(deads)
        L = [0]*maxl
        print(maxl)
        for i in deads:
            L[i - 1] += 1
        return L

    # dessine le graph de mort par génération
    def draw_death(self):
        y = self._get_n_deads()
        x = list(range(0,len(y) - 1))
        iplot([{"x": x, "y": y}])

    # retourne la liste des traits
    def list_traits(self):
        self.cursor.execute("PRAGMA table_info(EVOLUTION);")
        sql = self.cursor.fetchall()
        L = []
        for i in sql:
            L.append(i[1])
        L.remove("DEAD")
        L.remove("GEN")
        L.remove("ID")
        L.remove("PAR1")
        L.remove("PAR2")
        return L

    # retourne la liste de traits (trait) par individus
    def _get_trait(self, trait):
        self.cursor.execute("SELECT "+trait+",GEN FROM EVOLUTION ORDER BY GEN")
        return self.cursor.fetchall()
    
    # retourne la liste de traits (trait) par individus vivant
    def _get_trait_alive(self, trait):
        self.cursor.execute("SELECT "+trait+",GEN FROM EVOLUTION WHERE DEAD = 0 ORDER BY GEN")
        return self.cursor.fetchall()

    #retourne le nombre de personne vivante à la génération i
    def _get_n_alive(self, i):
        self.cursor.execute("SELECT Count(*) FROM EVOLUTION WHERE GEN <= "+str(i)+" AND (DEAD = 0 OR DEAD >= "+str(i)+")")
        res = self.cursor.fetchall()
        return res[0][0]

    # dessine le graph de nombre de personne vivante par génération
    def draw_alive(self):
        n = 0
        L = []
        while n < self.cycle:
            res = self._get_n_alive(n)
            L.append(res)
            n += 1
        
        y = L
        x = list(range(0,len(y) - 1))
        iplot([{"x": x, "y": y}])

    #retourne un couple avec deux tableaux en fonction du trait: ltr: les traits, Lgen: la génération de l'individu
    def couple_trait(self, trait):
        L = self._get_trait(trait)
        Ltr = []
        Lgen = []
        for i in L:
            Ltr.append(i[0])
            Lgen.append(i[1])
        return (Ltr,Lgen)

    #retourne un couple avec deux tableaux en fonction du trait: ltr: les traits, Lgen: la génération de l'individu vivant
    def couple_trait_alive(self, trait):
        L = self._get_trait_alive(trait)
        Ltr = []
        Lgen = []
        for i in L:
            Ltr.append(i[0])
            Lgen.append(i[1])
        return (Ltr,Lgen)

    # créér une liste de liste à partir d'un couple: liste de trait par génération
    def list_by_gen(self,L):
        maxL = max(L[1])
        new = [[] for i in range((maxL+1))]
        for i in range(len(L[1])):
            n = L[1][i]
            new[n].append(L[0][i])
        
        return new
    
    # affiche des statistiques basiques
    def simple_stat(self):
        data = [["trait","n", "moyenne", "equart-type", "min", "max"]]
        traits = self.list_traits()
        for tr in traits:
            L = self.couple_trait_alive(tr)
            data_tr = [tr]
            data_tr.append(len(L[0]))
            data_tr.append(mean(L[0]))
            data_tr.append(stdev(L[0]))
            data_tr.append(min(L[0]))
            data_tr.append(max(L[0]))
            data.append(data_tr)
        table_to_html(data)
    
    # dessines des statistiques en fonction du temps
    def draw_stats(self,trait):
        L = self.list_by_gen(self.couple_trait(trait))
        #print(str(L[0][0]) + " " + str(L[1][0]))
        moy = [0]*len(L)
        minl = [0]*len(L)
        maxl = [0]*len(L)
        equart = [0]*len(L)
        for i in range(len(L)):
            moy[i] = mean(L[i])
            minl[i] = percentile(L[i], 17) #min(L[i])
            maxl[i] = percentile(L[i], 83) #max(L[i])
            equart[i] = stdev(L[i])
        list_x = list(range(len(L)-1))
        y = maxl

        trace0 = go.Scatter(
            x = list_x,
            y = minl,
            mode = 'lines',
            name = '1/6'
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
            name = '5/6'
        )

        trace3 = go.Scatter(
            x = list_x,
            y = equart,
            mode = 'lines',
            name = 'equart type'
        )
        iplot([trace0,trace1,trace2,trace3])


    def draw_tree(self,i, trait, n = None):
        if(n != None and n > 5):
            print("n too big (<5)")
            return None
        q = Queue()
        q.put(i)
        q.put(None)
        dot = Digraph(comment="tree based on "+str(i))
        val = round(self._get_trait_ind(i,trait),3)
        dot.node(str(i), str(val))
        while(not (q.empty())):
            cur = q.get()
            if(cur == None):
                if(n != None):
                    if(n <= 0):
                        break
                    else:
                        n -= 1
                        print("## "+str(n)+" ##")
                if(not(q.empty())):
                    q.put(None)
            else:
                print(cur)
                pars = self._get_parents_ind(cur)

                if pars:
                    q.put(pars[0])
                    q.put(pars[1])
                    val1 = round(self._get_trait_ind(pars[0],trait),3)
                    val2 = round(self._get_trait_ind(pars[1],trait),3)
                    dot.node(str(pars[0]),str(val1))
                    dot.node(str(pars[1]),str(val2))
                    dot.edge(str(pars[0]),str(cur))
                    dot.edge(str(pars[1]),str(cur))
        return dot