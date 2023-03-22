#include "Snake.hpp"

void display(struct pixel* pixels){
    int lastindex = wide * hight - 1;
    int index = 0;

    system("cls");  //调用cmd清屏
    std::cout << "Using 'a''s''d''w' to change direction"<<'\n';
    for (int i = 0; i < hight; i++){
        for (int j = 0; j < wide; j++){
            if ( pixels -> type == "wall"){
                std::cout << " #";
            }
            else if (pixels -> type == "vacant"){
                std::cout << "  ";
            }
            else if (pixels -> type == "food")
            {
                std::cout << " *";
            }
            else if (pixels -> type == "head")
            {
                std::cout << "()";
            }
            else if (pixels -> type == "body")
            {
                std::cout << " O";
            }
     
            if (index == lastindex){
                return;
            }
            index ++;
            pixels++;

        }
        std::cout << '\n';
        
    }
    
}
int randint(int max, int min)
{
    //std::random_device rd;
	std::uniform_int_distribution<> distr(min, max); //生成实数可用uniform_real_distribution
	// std::mt19937 gen(rd()); //可换为std::default_random_engine，但建议用mt19937
	// int random = distr(gen);
    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    if (max - min <= 0){
        return 0;
    }
    int random = distr(gen);
    return random;

}

int getindex(int x, int y){
    int index = y*wide + x -1;
    return index;
}

char keydetect(){
    char ch;
    while (1) {
 
        if ( kbhit() ) {
 
            // Stores the pressed key in ch
            ch = getch();
 
            // Terminates the loop
            // when escape is pressed
            // if (int(ch) == 27)
            return ch;
        }
    }
}