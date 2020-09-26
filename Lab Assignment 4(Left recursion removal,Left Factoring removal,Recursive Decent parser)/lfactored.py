from collections import defaultdict

state = 1

def print_productions(prod):
	for key,values in prod.items():
		print(key,end=' -> ')
		for i in range(len(values)):
			if i==len(values)-1:
				print(values[i])
				continue
			print(values[i],end=' | ')

def leftfac(prod,k):
	global state
	productions = prod[k]
	firstchar = defaultdict(list)
	for i in productions:
		if len(i)==1:
			firstchar[i[0]].append('$')
		else:
			firstchar[i[0]].append(i[1:])
	if len(firstchar) == len(productions):
		return
	newprod = []
	for key, value in firstchar.items():
		if len(value)==1:
			if value[0]!='$':
				newprod.append(key+value[0])
			else:
				newprod.append(key)
			continue
		newstate = 'S'+str(state)
		state = state+1
		newprod.append(key+newstate)
		prod[newstate] = value
		leftfac(prod,newstate)
	prod[k] = newprod
	#print(firstchar)

prod = defaultdict(list)

while True:
	l=input()
	if l=='END':
		break
	l = l.split('->')
	#print(l[1].split('|'))
	prod[l[0]]=(l[1].split('|'))

states = []
for key in prod.keys(): 
	states.append(key)

for i in states:
	leftfac(prod,i)

print_productions(prod)