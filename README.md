# Maze

Goals: Understand recursion and solve a maze

Given a text file representing a maze, as below, find the path for
creature to get to the exit and mark the path explored.
```
20 7
0 18
xxxxxxxxxxxxxxxxxx x
x     x       xxxx x
x xxxxx xxxxx   xx x
x xxxxx xxxxxxx xx x
x x          xx xx x
x xxxxxxxxxx xx    x
xxxxxxxxxxxxxxxxxxxx
```

Solution:
`*` shows the final path to exit

`+` shows areas explored but not part of the final path

```
Path: EEENNNEEEEEESEESSSEEENNNNN
xxxxxxxxxxxxxxxxxx*x
x     x*******xxxx*x
x xxxxx*xxxxx***xx*x
x xxxxx*xxxxxxx*xx*x
x x+****+++++xx*xx*x
x xxxxxxxxxx+xx****x
xxxxxxxxxxxxxxxxxxxx
```

## Compile and Run

```
./simplecompile.sh
```
