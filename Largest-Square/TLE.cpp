#include <iostream>

#define tile(i,j) tile[(j) * (H) +(i)]

int calc(int x, int y, int* tile, int H, int W){
    int k = std::min(H-x, W-y);
    //std::cout << k << std::endl;
    
    if(tile(x,y) == 1){
        return 0;
    }
    
    for(int s=0; s<k; ++s){
        for(int i=0; i<=s; ++i){
            for(int j=0; j<=s; ++j){
                if(tile(x + i, y + j) == 1){
                    return s;
                }
            }
        }
    }

    return k;
}

int main(){
    int H, W;
    std::cin >> H >> W;
    int* tile = new int[H * W];
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            std::cin >> tile(i,j);
        }
    }
    
    int ans = 0;
    
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            //std::cout << calc(i, j, tile, H, W) << std::endl;
            ans = std::max(calc(i, j, tile, H, W), ans);
        }
        //std::cout << std::endl;
    }
    std::cout << ans*ans << std::endl;
    delete[] tile;
}