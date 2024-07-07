#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int find(char** word_list, char* word, int size_list){
    int found = 0;
    for (int i =0; i < size_list; i++){
        if(strcmp(word_list[i], word) == 0){
            found = 1;
            break;
        } 
    }

    return found;

}

int main(){
    char* list_of_words[] = {"about","above","abuse","actor","acute","admit","adopt","adult","after","again","agent","agree","ahead","alarm","album","alert","alike","alive","allow","alone","along","alter","among","anger","angle","angry","apart"};//,apple,apply,arena,argue,arise,array,aside,asset,audio,audit,avoid,award,aware,badly,baker,bases,basic,basis,beach,began,begin,begun,being,below,bench,billy,birth,black,blame,blind,block,blood,board,boost,booth,bound,brain,brand,bread,break,breed,brief,bring,broad,broke,brown,build,built,buyer,cable,calif,carry,catch,cause,chain,chair,chart,chase,cheap,check,chest,chief,child,china,chose,civil,claim,class,clean,clear,click,clock,close,coach,coast,could,count,court,cover,craft,crash,cream,crime,cross,crowd,crown,curve,cycle,daily,dance,dated,dealt,death,debut,delay,depth,doing,doubt,dozen,draft,drama,drawn,dream,dress,drill,drink,drive,drove,dying,eager,early,earth,eight,elite,empty,enemy,enjoy,enter,entry,equal,error,event,every,exact,exist,extra,faith,false,fault,fiber,field,fifth,fifty,fight,final,first,fixed,flash,fleet,floor,fluid,focus,force,forth,forty,forum,found,frame,frank,fraud,fresh,front,fruit,fully,funny,giant,given,glass,globe,going,grace,grade,grand,grant,grass,great,green,gross,group,grown,guard,guess,guest,guide,happy,harry,heart,heavy,hence,henry,horse,hotel,house,human,ideal,image,index,inner,input,issue,japan,jimmy,joint,jones,judge,known,label,large,laser,later,laugh,layer,learn,lease,least,leave,legal,level,lewis,light,limit,links,lives,local,logic,loose,lower,lucky,lunch,lying,magic,major,maker,march,maria,match,maybe,mayor,meant,media,metal,might,minor,minus,mixed,model,money,month,moral,motor,mount,mouse,mouth,movie,music,needs,never,newly,night,noise,north,noted,novel,nurse,occur,ocean,offer,often,order,other,ought,paint,panel,paper,party,peace,peter,phase,phone,photo,piece,pilot,pitch,place,plain,plane,plant,plate,point,pound,power,press,price,pride,prime,print,prior,prize,proof,proud,prove,queen,quick,quiet,quite,radio,raise,range,rapid,ratio,reach,ready,refer,right,rival,river,robin,roger,roman,rough,round,route,royal,rural,scale,scene,scope,score,sense,serve,seven,shall,shape,share,sharp,sheet,shelf,shell,shift,shirt,shock,shoot,short,shown,sight,since,sixth,sixty,sized,skill,sleep,slide,small,smart,smile,smith,smoke,solid,solve,sorry,sound,south,space,spare,speak,speed,spend,spent,split,spoke,sport,staff,stage,stake,stand,start,state,steam,steel,stick,still,stock,stone,stood,store,storm,story,strip,stuck,study,stuff,style,sugar,suite,super,sweet,table,taken,taste,taxes,teach,teeth,terry,texas,thank,theft,their,theme,there,these,thick,thing,think,third,those,three,threw,throw,tight,times,tired,title,today,topic,total,touch,tough,tower,track,trade,train,treat,trend,trial,tried,tries,truck,truly,trust,truth,twice,under,undue,union,unity,until,upper,upset,urban,usage,usual,valid,value,video,virus,visit,vital,voice,waste,watch,water,wheel,where,which,while,white,whole,whose,woman,women,world,worry,worse,worst,worth,would,wound,write,wrong"};
    int list_size = sizeof(list_of_words)/sizeof(list_of_words[0]);

    srand(time(NULL)); // Seed the random number generator to prevent it from always giving the same value
    int random = rand() % list_size; // Generate a random index within the array bounds

    char* word_chosen = list_of_words[random];
    printf("word: %s\n", word_chosen);
    char* word_entered = malloc(sizeof(char)*6);
    int tries = 0;
    char to_return[5] = "aaaaa";
    while ((word_chosen != word_entered) && tries < 5){
        printf("Enter your guess here: ");
        scanf("%5s", word_entered);  //only scan the first 5 characters
        if(strlen(word_entered) != 5 || find(list_of_words, word_entered, list_size) == 0){
            printf("Please ensure your guess is exactly 5 letters and a recognized word in the english dictionary\n");
        }
        else{
            if (word_entered[0] == word_chosen[0] && word_entered[1] == word_chosen[1] && word_entered[2] == word_chosen[2] && word_entered[3] == word_chosen[3] && word_entered[4] == word_chosen[4]){
                printf("Congratulations! You guessed %s correctly. It took you %d tries\n", word_chosen, tries+1);
                break;
    } 
            for (int i = 0; i < 5; i++){
                if(word_entered[i] == word_chosen[i]) {
                    char capitalized = word_chosen[i];
                    capitalized = capitalized -32;
                    to_return[i] = capitalized; // capitalized
                } else if (word_entered[i] == word_chosen[0] || word_entered[i] == word_chosen[1] || word_entered[i] == word_chosen[2] || word_entered[i] == word_chosen[3] || word_entered[i] == word_chosen[4] ){
                        to_return[i] = word_entered[i]; // lowercase
                        //add the case where the letter has already been marked as there and so shouldn't show up a second time
                }else { 
                        to_return[i] = '_';
                    }
                }
                printf("%s\n", to_return);
                tries++;
        }


    }

    if(word_chosen != word_entered && tries >= 5){
        printf("Sorry, you have no more tries left. The word was %s. Better luck next time!", word_chosen);
    }

    free(word_entered);

    return 0;
}