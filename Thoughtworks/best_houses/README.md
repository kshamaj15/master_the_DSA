Alice and bob two friend want to buy the house
there are houses in N x N matrix
G[i][j] indicates the quality of house
They don't want to live to far with each other and want the house with good quality
Happiness =  G[i1][j1] + G[i2][j2] - abs(i1-i2) - abs(j1-j2)
find the max possible happiness

example

1 9 1 1
1 1 4 1
3 4 1 2
1 2 7 7

max happiness = 13 when they buy house 
G[3][4] = 7
G[4][4] = 7
