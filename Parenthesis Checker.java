class Solution
{
    static boolean ispar(String x)
    {
        Stack<Character> s=new Stack<>();
        for(int i=0;i<x.length();i++){
            char ch=x.charAt(i);
            
            if(ch=='[' || ch=='{' || ch=='('){
                s.push(ch);
                continue;
            }
            
            if(s.empty())
                return false;
                
            if(ch==']'){
                if(s.peek()=='[')
                    s.pop();
                else
                    return false;
            }
            
            if(ch==')'){
                if(s.peek()=='(')
                    s.pop();
                else
                    return false;
            }
            
            if(ch=='}'){
                if(s.peek()=='{')
                    s.pop();
                else
                    return false;
            }
            
        }
        
        if(s.empty())
            return true;
        else
            return false;
    }
}
