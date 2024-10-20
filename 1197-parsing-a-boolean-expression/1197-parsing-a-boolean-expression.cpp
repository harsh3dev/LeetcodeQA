class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch : expression){
            if(ch==',' || ch=='(') continue;

            if(ch == '&' || ch == '|' || ch == '!' || ch == 't' || ch == 'f'){
                st.push(ch);
            }
            else if( ch == ')' ){
                bool trueflag = false, falseflag = false;

                while(st.top() != '!' && st.top() != '&' && st.top() != '|'){
                    char value = st.top();
                    st.pop();
                    if(value == 't') trueflag = true;
                    if(value == 'f') falseflag = true;
                }
                // Evaluate result
                char oper = st.top();
                st.pop();

                if(oper == '!'){
                    st.push(trueflag ? 'f' : 't');
                }
                else if(oper == '&'){
                    st.push(falseflag ? 'f' : 't');
                } else {
                    st.push(trueflag ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};


// NAIVE Approach
/*
* implement using 2 stack expression and value
* traverse through the string and if any expression is found i.e: (,),&,|,!
* put the expression into the expression stack
* if any value is found like t, f --> put it into the value stack
* if , is found then ignore and move forward
* if closing bracket is found then evalluate the exp by popping from the stack 
*/

// Better Approach
/*
* we should use only 1 stack for both the values and operators
* if one of the value is false and op is & then res is false else true
* if one of the operator is true and the op is | then the res is true else false
*/