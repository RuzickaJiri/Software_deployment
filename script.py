import my_wrapper_c as mwc
import matplotlib.pyplot as plt

stringTable=["x1","x2","x3","x4","x5"]
g=mwc.create_generation(10,stringTable)
mwc.print_formulas(g)
tableoffitness=mwc.compute_fitness(g)
#xlabels=["x1","x2","x3","x4","x5"]
x=[[1,1,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
y=[1,1,0,0,1,1,1]
#&n,&pyListBoolx,&pyListInty,&record


g2=mwc.evolve(True,14,x,y,g)

mwc.print_formulas(g2)


g2=mwc.evolve(True,14,x,y,g2)
mwc.print_formulas(g2)

ft=mwc.compute_fitness(g)
tab=[]
for i in range (0,10):

 g2=mwc.evolve(50,140,x,y,g2)
 maxf=min(mwc.compute_fitness(g2))
 tab.append(maxf)
 print()
 print("Best formula after ",i ," evolution")
 print()
 mwc.print_best_formula(x,y,g2)
 print()
 print()
 print()

plt.plot(range (0,10), tab, 'ro')
plt.axis([0, 10, 0, 5])
plt.show()

x2=[[1,1,0],[1,0,1],[0,1,0],[1,1,1],[1,0,1],[1,1,0],[0,1,0],[0,1,0],[0,1,0],[0,1,0],[0,0,0],[0,1,1],[0,1,1],[0,1,1],[1,1,0],[0,0,0],[0,1,0]]
y2=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

tab=[]

for i in range (0,10):
 g2=mwc.evolve(5,5,x2,y2,g2)
 maxf=min(mwc.compute_fitness(g2))
 tab.append(maxf)
 print()
 print("Best formula after ",i ," evolution")
 print()
 mwc.print_best_formula(x,y,g2)
 print()
 print()
 print()
plt.plot(range (0,10), tab, 'ro')
plt.axis([0, 10, 0, 5])
plt.title('Fitness evolution in different generations')
plt.show()


#help(mwc.create_generation)
#help(mwc)
