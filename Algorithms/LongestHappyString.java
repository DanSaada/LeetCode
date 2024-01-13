class Solution {
    public String longestDiverseString(int a, int b, int c) {
        if (a == 0 && b == 0 && c == 0) {return "";}
        StringBuilder sb = new StringBuilder();

        int aCounter = 0;
        int bCounter = 0;
        int cCounter = 0;
        int length = a + b + c;
        
        
        for (int i = 0 ; i < length; i++) {
            if( (a >= b && a >= c && aCounter < 2) || (bCounter == 2 && a > 0) 
            || (cCounter == 2 && a > 0) ){
                sb.append('a');
                a--;
                aCounter++;
                bCounter = 0;
                cCounter = 0;
            }
            
            else if( (b >= a && b >= c && bCounter < 2) || (aCounter == 2 && b > 0) 
            || (cCounter == 2 && b > 0) ){
                sb.append('b');
                b--;
                bCounter++;
                aCounter=0;
                cCounter=0;
            }
            
            else if( (c >= b && c >= a && cCounter < 2) || (bCounter == 2 && c > 0) 
            || (aCounter == 2 && c > 0) ){
                sb.append('c');
                c--;
                cCounter++;
                bCounter=0;
                aCounter=0;
            }
        }
        
        return sb.toString();
    }
}