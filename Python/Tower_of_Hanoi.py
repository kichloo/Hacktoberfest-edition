# Recursive Python function to solve the tower of hanoi 
  
def TowerOfHanoi(n , source, destination, auxiliary): 
    if n==1: 
        print "Move disk 1 from source",source,"to destination",destination 
        return
    TowerOfHanoi(n-1, source, auxiliary, destination) 
    print "Move disk",n,"from source",source,"to destination",destination 
    TowerOfHanoi(n-1, auxiliary, destination, source) 
          
# Driver code 
n = 4
TowerOfHanoi(n,'A','B','C')  
# A, C, B are the name of rods 


Output: 

 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 3 from rod A to rod B
 Move disk 1 from rod C to rod A
 Move disk 2 from rod C to rod B
 Move disk 1 from rod A to rod B
 Move disk 4 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 2 from rod B to rod A
 Move disk 1 from rod C to rod A
 Move disk 3 from rod B to rod C
 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
