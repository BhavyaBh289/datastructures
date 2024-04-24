class Graph:
    def __init__(self, num):
        self.data = [0] * num
        self.graph = {}
    def printmax(self):
        max_index = self.data.index(max(self.data))
        print(max_index ,"is the highest with value ",max(self.data))
    def add_bug(self, bug_id, occ):
        if(self.data[bug_id]!=0):
            self.data[bug_id] = occ
            self.addtoparent(bug_id)
    def add_edge(self, b, p , perc):
        if b in self.graph:
            self.graph[b].append((p,perc))
        else:
            self.graph[b]=[(p,perc)]
    def print_graph(self):
        for i in self.data:
            print(i);
        for b, edges in self.graph.items():
            print(f'Bug {b} (Parent Bugs and Percentages):')
            for parent, percentage in edges:
                print(f'  - Parent Bug: {parent}, Percentage: {percentage}')
    def addtoparent(self,bug_id):
        try:
            if(self.graph[bug_id]):
                for parent,percentage in self.graph[bug_id]:
                    self.data[parent] += self.data[bug_id] * percentage

                for parent,percentage in self.graph[bug_id]:
                    if(self.data[parent]==0):
                        self.addtoparent(parent)
                    else:
                        self.addtoparents(parent,self.data[bug_id] * percentage)
        except:
            pass
    def addtoparents(self,bug_id,n):
        if self.data[bug_id] is not None:
            try:
                if(self.graph[bug_id]):
                    for parent,percentage in self.graph[bug_id]:
                        self.data[parent] += n * percentage
                        self.addtoparents(parent,n * percentage)
            except:
                pass

import pandas as pd

df = pd.read_csv('bugs_data.tsv', sep='\t')

df_null = df[df['occurrences'].isnull()].sort_values(by='edge_id')

df_non_null = df[df['occurrences'].notnull()].sort_values(by='occurrences')

t = df[['parent_bug_id', 'bug_id']].max(axis=1)
i = max(t)
g = Graph(i+1)

for index, row in df_null.iterrows():
    bug_id = int(row['bug_id'])
    parent_bug_id = int(row['parent_bug_id'])
    percentage_contribution = float(row['percentage_contribution']) / 100
    g.add_edge(bug_id,parent_bug_id,percentage_contribution)

for index, row in df_non_null.iterrows():
    bug_id = int(row['bug_id'])
    parent_bug_id = int(row['parent_bug_id'])
    percentage_contribution = float(row['percentage_contribution']) / 100
    occurrences = int(row['occurrences'])
    g.add_edge(bug_id,parent_bug_id,percentage_contribution)

for index, row in df_non_null.iterrows():
    bug_id = int(row['bug_id'])
    parent_bug_id = int(row['parent_bug_id'])
    occurrences = int(row['occurrences'])
    g.add_bug(bug_id,occurrences)


g.printmax()
g.print_graph()
