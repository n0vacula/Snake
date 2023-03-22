#include "Snake.hpp"


int gameinit(struct pixel* pixels){
    int lastindex = wide * hight - 1;
    int index = 0;
    int head = 0;
    int snakex = wide/2;
    int snakey = hight/2;

    for (int i = 0; i < hight; i++){
        for (int j = 0; j < wide; j++){
            if (j == 0 || j == wide - 1 || i == 0 || i == hight - 1){
                pixels -> type = "wall";
            }
            else if (j == snakex && i == snakey)
            {
                pixels -> type = "head";
                head = index;
            }
            
            else{
                pixels -> type = "vacant";
            }

            if (index == lastindex){
                return head;
            }
            index ++;
            pixels++;
        }
    }

}

void food(struct pixel* pixels){
    lenth++;
    for(int i; i<1000; i++)
    {
        int x = randint( wide-1 , 1);
        int y = randint( hight-1 , 1);
        int index = getindex(x, y);
        std::string temp = (pixels + index) -> type;
        if (temp != "wall" && temp != "head" && temp != "body")
        {
            (pixels + index) -> type = "food";
            std::cout << "food:"<<x<<" ,"<< y << '\n';
            lenth++;
            event = 0;
            return;
        }

        
    }

}

void move(struct snake* head, char ch){
    int jump = 0 ;
    switch (derection)
    {
    case 'a':
        jump = -1;
        break;
    case 's':
        jump = wide;
        break;
    case 'd':
        jump = 1;
        break;
    case 'w':
        jump = -wide;
        break;
    default:
        break;
    }
    struct snake **ptr = &head;
    
    //block detection
    std::string* found = &(head->pixel+jump)->type;

    //found food
    if (*found == "food")
    {
        std::string body= "body";
        *found = body;
        event = 1;

        //add tail
        while ((*ptr)->next){
            ptr = &((*ptr)->next);
        }
        struct snake *tail;
        tail = new snake;
        tail->pre = *ptr;
        tail->next = nullptr;
        tail->pixel = nullptr;
        (*ptr)->next = tail;
    }
    else if ((*found == "wall" || *found == "body"))
    {
        event = 2;
    }
    
    

    //switch blocks
    struct pixel temppixel = *(head->pixel);
    *(head ->pixel) = *(head-> pixel + jump);
    *(head->pixel+ jump) = temppixel;
    
    
    ptr = &head;
    while ((*ptr)->next)
    {
        
        temppixel = *((*ptr)->pixel);
        if (!(*ptr)->next->pixel)
        {
            ptr = &((*ptr)->next);
            break;
        }
        *((*ptr)->pixel) = *((*ptr)->next->pixel);
        *((*ptr)->next->pixel) = temppixel;
        ptr = &((*ptr)->next);
    }
    while ((*ptr)->pre)
    {
        (*ptr)->pixel = (*ptr)->pre->pixel;
        ptr = &((*ptr)->pre);
    }

    head ->pixel = head-> pixel + jump;
    return;
}

void gameover(){
    system("cls");  //调用cmd清屏
    std::cout<< "gameover";
    event = 99;
    system("pause");
    return;
}
