/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortinsert(stack<int>& s,int temp)
{
    if(s.empty() || temp>s.top())
    {
        s.push(temp);
        return;
    }
    int x=s.top();
    s.pop();
    sortinsert(s,temp);
    s.push(x);
}
void SortedStack :: sort()
{
   if(!s.empty())
   {
       int temp=s.top();
       s.pop();
       sort();
       sortinsert(s,temp);
   }
}