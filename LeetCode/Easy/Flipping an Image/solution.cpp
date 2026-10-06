class Solution {
public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r = image.size();
        int c = image[0].size();

        for (int i = 0; i < r; i++) {
            int st = 0, end = c - 1;
            while (st <= end) {
                if(st==end){
                     image[i][end]=(! image[i][end]);
                     break;
                }
                swap(image[i][st], image[i][end]);
                image[i][st] = (!image[i][st]);
                image[i][end] = (!image[i][end]);
                st++;end--;
            }

        }
        return image;
    }
};