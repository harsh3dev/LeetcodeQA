class Solution {
public:
    bool canTransform(string start, string end) {
        string withOutXS = "", withOutXE = "";
        for(int i=0;i<start.size();i++) {
            if(start[i] !='X') {
                withOutXS += start[i];
            }
            if(end[i] != 'X') {
                withOutXE += end[i];
            }
        }
        if(withOutXS != withOutXE) {
            return false;
        }

        int startI = 0, endI = 0;
        int upX = 0, lowX = 0;
        while(startI<start.size() && endI<end.size()) {
            
            if(start[startI]=='X' && lowX) {
                startI++; lowX--;
            } else if(end[endI]=='X' && upX) {
                endI++; upX--;
            } else if(start[startI]==end[endI]) {
                startI++;
                endI++;
            } else if(start[startI]=='R' && end[endI]=='X') {
                endI++;
                lowX++;
            } else if(start[startI]=='X' && end[endI]=='L') {
                startI++; upX++;
            } else {
                return false;
            }
        }

        while(startI<start.size() && lowX) {
            if(start[startI]!='X') {
                return false;
            }
            lowX--;
        }

        while(endI<end.size() && upX) {
            if(end[endI]!='X') {
                return false;
            }
            upX--;
        }
        if(upX>0 || lowX>0) {
            return false;
        }

        return true;
    }
};