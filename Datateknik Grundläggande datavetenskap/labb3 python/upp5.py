tal1 = int(input("Skriv in ett tal: "))    
tal2 = int(input("Skriv in ett andra tal: "))
M = max(tal1, tal2)
N = min(tal1, tal2)

R = M % N
while R != 0:
    M = N
    N = R 
    R = M % N

print("Den största gemensamma nämnaren av " + str(tal1) + " och " + str(tal2) + " är: " + str(N))
#print(str(M) + " är den största gemensamma nämnaren av " + str(tal1) + " och " + str(tal2) + ".")
