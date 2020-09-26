from collections import defaultdict

def print_productions(productions):
	for key,values in productions.items():
		print(key,end=' -> ')
		for i in range(len(values)):
			for j in values[i]:
				print(j,end='')
			if i==len(values)-1:
				continue
			print(' | ',end='')
		print()

def remdirectlr(productions, A):
	temp = productions[A]
	tempCr = []
	tempInCr = []
	for i in temp:
		if i[0] == A:
			tempInCr.append(i[1:]+[A+"'"])
		else:
			tempCr.append(i+[A+"'"])
	tempInCr.append(["$"])
	productions[A] = tempCr
	productions[A+"'"] = tempInCr
	return productions


def checkindirect(productions, a, ai):
	if ai not in productions:
		return False 
	if a == ai:
		return True
	for i in productions[ai]:
		if i[0] == ai:
			return False
		if i[0] in productions:
			return checkindirect(productions, a, i[0])
	return False

def repeat(productions, A):
	temp = productions[A]
	newTemp = []
	for i in temp:
		if checkindirect(productions, A, i[0]):
			t = []
			for k in productions[i[0]]:
				t=[]
				t+=k
				t+=i[1:]
				newTemp.append(t)

		else:
			newTemp.append(i)
	productions[A] = newTemp
	return productions

def remove(prod):
	c = 1
	conv = {}
	productions = {}
	revconv = {}
	for j in prod:
		conv[j] = "A"+str(c)
		productions["A"+str(c)] = []
		c+=1

	for i in prod:
		for j in prod[i]:
			temp = []	
			for k in j:
				if k in conv:
					temp.append(conv[k])
				else:
					temp.append(k)
			productions[conv[i]].append(temp)


	for i in range(c-1,0,-1):
		ai = "A"+str(i)
		for j in range(0,i):
			aj = productions[ai][0][0]
			if ai!=aj :
				if aj in productions and checkindirect(productions,ai,aj):
					productions = repeat(productions, ai)

	for i in range(1,c):
		ai = "A"+str(i)
		for j in productions[ai]:
			if ai==j[0]:
				productions = remdirectlr(productions, ai)
				break

	op = {}
	for i in productions:
		a = str(i)
		for j in conv:
			a = a.replace(conv[j],j)
		revconv[i] = a

	for i in productions:
		l = []
		for j in productions[i]:
			k = []
			for m in j:
				if m in revconv:
					k.append(m.replace(m,revconv[m]))
				else:
					k.append(m)
			l.append(k)
		op[revconv[i]] = l

	return op

prod = defaultdict(list)

while True:
	l=input()
	if l=='END':
		break
	l = l.split('->')
	#print(l[1].split('|'))
	prod[l[0]]=(l[1].split('|'))

#print(prod)

result = remove(prod)

print_productions(result)