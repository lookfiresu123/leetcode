#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compute_first_rectangle(int first_x_min,int first_y_min,int first_x_max,int first_y_max){
    int result = (first_x_max - first_x_min) * (first_y_max - first_y_min);
    return result;
}

int compute_second_rectangle(int second_x_min,int second_y_min,int second_x_max,int second_y_max){
    int result = (second_x_max - second_x_min) * (second_y_max - second_y_min);
    return result;
}

int compute_coverd_rectangle(int first_x_min,int first_y_min,int first_x_max,int first_y_max,
                            int second_x_min,int second_y_min,int second_x_max,int second_y_max){
    int result = 0;
    if( first_x_min >= second_x_max ||
        first_x_max <= second_x_min ||
        first_y_min >= second_y_max ||
        first_y_max <= second_y_min )
        result = 0;
    else{
        //sort the x into 4 position and sort the y into 4 position
        int x[4],y[4];
        if(first_x_min <= second_x_min){
            x[0] = first_x_min;
            x[1] = second_x_min;
            if(first_x_max <= second_x_max){
                x[2] = first_x_max;
                x[3] = second_x_max;
            }
            else{
                x[2] = second_x_max;
                x[3] = first_x_max;
            }
        }
        else{
            x[0] = second_x_min;
            x[1] = first_x_min;
            if(first_x_max <= second_x_max){
                x[2] = first_x_max;
                x[3] = second_x_max;
            }
            else{
                x[2] = second_x_max;
                x[3] = first_x_max;
            }
        }
        if(first_y_min <= second_y_min){
            y[0] = first_y_min;
            y[1] = second_y_min;
            if(first_y_max <= second_y_max){
                y[2] = first_y_max;
                y[3] = second_y_max;
            }
            else{
                y[2] = second_y_max;
                y[3] = first_y_max;
            }
        }
        else{
            y[0] = second_y_min;
            y[1] = first_y_min;
            if(first_y_max <= second_y_max){
                y[2] = first_y_max;
                y[3] = second_y_max;
            }
            else{
                y[2] = second_y_max;
                y[3] = first_y_max;
            }
        }
        //compute the area
        result = (x[2] - x[1]) * (y[2] - y[1]);
    }
    return result;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int first_x_min = A<=C?A:C;
    int first_y_min = B<=D?B:D;
    int first_x_max = C<A?A:C;
    int first_y_max = D<B?B:D;
    int second_x_min = E<=G?E:G;
    int second_y_min = F<=H?F:H;
    int second_x_max = G<E?E:G;
    int second_y_max = H<F?F:H;
    int first_rectangle_area = compute_first_rectangle(first_x_min,first_y_min,first_x_max,first_y_max);
    int second_rectangle_area = compute_second_rectangle(second_x_min,second_y_min,second_x_max,second_y_max);
    int coverd_rectangle_area = compute_coverd_rectangle(first_x_min,first_y_min,first_x_max,first_y_max,
                                                        second_x_min,second_y_min,second_x_max,second_y_max);
    int result = first_rectangle_area + second_rectangle_area - coverd_rectangle_area;
    return result;
}

int main(){
    int result = computeArea(-3,0,3,4,0,-1,9,2);
    printf("%d\n",result);
    return 0;
}
