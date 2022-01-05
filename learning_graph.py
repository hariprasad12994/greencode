from graphviz import Digraph

dot = Digraph()

dot.node('C++', 'C++')
dot.node('Concurrency', 'Concurrency')
dot.node('Atomics', 'Atomics')

dot.edge('C++', 'Concurrency')
dot.edge('Concurrency', 'Atomics')

dot.format = 'png'
dot.render('learning_graph', view=True)

