import sqlite3
import subprocess
import os
from pathlib import Path
from plotly import __version__
from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot

def run_chnabeltier(depart, cycle, nom):
    file = Path(nom)
    if file.is_file():
        os.remove(file)
    
    args = ("./main", str(depart), str(cycle), nom)
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()
    print(popen.stdout.read())

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

def test_plot():
    iplot([{"x": [1, 2, 3], "y": [3, 1, 6]}])

