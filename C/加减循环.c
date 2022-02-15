void circle(char c,int distance,int *now,int up,int down)
{
    if(c=='+')  *now=down+(*now-down+distance)%(up-down+1);
    else if(c=='-') *now=up-(up-*now+distance)%(up-down+1);
}
