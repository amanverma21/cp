class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=((ay2-ay1)*(ax2-ax1));
        int area2=((by2-by1)*(bx2-bx1));
        int xlap=(min(ax2,bx2)-max(ax1,bx1));
        int ylap=(min(ay2,by2)-max(ay1,by1));
        int ans=0;
        if(xlap>0 && ylap>0)
            ans=xlap*ylap;
        int res=area1+area2-ans;
        return res;
    }
};