#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void set_start(char print[], const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        print[i] = '*';
    }
    print[i] = '\0';
}

bool set(const char* str, char letter, char print[]) {
    bool found = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letter) {
            print[i] = str[i];
            found = true;
        }
    }
    return found;
}

void ptint(char print[], int count) {
    for (int i = 0; i < count; i++)
    {
        cout << "[" << i + 1 << "]";
        cout << "♥ ";
    }
    cout << "\n" << string(50, '-') << "\n";
    for (int i = 0; print[i] != '\0'; i++) {
        cout << print[i] << " ";
    }
    cout << "\n" << string(50, '-') << "\n";
}

void ptint_arr(const char* str) {
    cout << "\n" << string(50, '-') << "\n";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << " ";
    }
    cout << "\n" << string(50, '-') << "\n";
}

bool is_win(const char* str) {
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*') {
            return false;
        }
    }
    return true;
}

void history_letters(char letter, char history[], int& history_count) {
    history[history_count] = letter;
    history_count++;
}

void print_history(char history[], int history_count) {
    cout << "Used letters: ";
    for (int i = 0; i < history_count; i++) {
        cout << history[i] << " ";
    }
    cout << "\n";
}

void menu(const char* str) {
    char print[100];
    char letter;

    char history[100];
    int history_count = 0;

    set_start(print, str);
    int count = strlen(str) + 2;
    system("color 0A");
    do {
        system("cls");
        ptint(print, count);
        print_history(history, history_count);
        cout << "\nEnter a letter: ";
        cin >> letter;
        history_letters(letter, history, history_count);
        if(!set(str, letter, print))
        count--;
        if (count == (strlen(str) + 2) / 2) {
            system("color 0E");
        }
        set(str, letter, print);
    } while (!is_win(print) && count != 0);
    if (count == 0) {
        system("cls");
        system("color 04");
        ptint_arr(str);
        print_history(history, history_count);
        cout << "You lose!";
    }else{
    system("cls");
    ptint(print, count);
    print_history(history, history_count);
    cout << "You win!🎉";
    }
}

int main()
{
    srand(time(NULL));
    SetConsoleOutputCP(65001); // для хлопушки 🎉;
    SetConsoleCP(65001);

    const char* words[] = {
"apple","banana","orange","grape","peach","mango","lemon","cherry","pear","plum","dog","cat","bird","fish","horse","mouse","rabbit","tiger","lion","wolf",
"house","door","window","floor","roof","wall","table","chair","bed","room","car","train","plane","boat","bike","truck","bus","road","street","bridge",
"water","fire","earth","wind","storm","rain","snow","ice","cloud","sky","sun","moon","star","space","planet","galaxy","comet","rocket","orbit","light",
"computer","keyboard","mouse","screen","monitor","laptop","server","network","internet","system","code","program","function","variable","loop","array","string","integer","class","object",
"game","player","level","score","win","lose","start","end","pause","menu","book","pen","paper","pencil","school","teacher","student","lesson","homework","exam",
"music","sound","voice","audio","video","movie","photo","image","camera","screen","happy","sad","angry","cool","fun","boring","fast","slow","big","small",
"strong","weak","hard","easy","simple","complex","random","logic","error","debug","time","day","night","week","month","year","today","tomorrow","yesterday","moment",
"energy","power","force","speed","distance","weight","mass","gravity","motion","speedup","red","blue","green","yellow","black","white","purple","pink","orange","gray",
"city","village","country","world","earth","continent","ocean","river","mountain","forest","food","bread","meat","milk","cheese","rice","soup","pizza","burger","cake",
"phone","call","message","chat","app","device","button","click","touch","type","data","file","folder","drive","disk","memory","storage","backup","upload","download",
"robot","ai","machine","engine","motor","gear","wheel","battery","charge","power","firewall","security","password","login","account","user","admin","system","access","control",
"html","css","java","python","cpp","code","script","build","compile","run","north","south","east","west","left","right","up","down","center","edge",
"attack","defend","fight","win","lose","battle","war","peace","army","weapon","gold","silver","money","coin","cash","bank","price","market","trade","shop",
"hot","cold","warm","cool","dry","wet","bright","dark","sharp","soft","tree","flower","grass","leaf","root","seed","plant","grow","nature","animal",
"jump","run","walk","sit","stand","move","stop","start","open","close","create","delete","update","edit","save","load","send","receive","connect","disconnect",
"alpha","beta","gamma","delta","omega","sigma","theta","lambda","zeta","kappa","cloud","server","client","node","edge","core","hub","link","sync","async",
"pixel","vector","canvas","render","draw","paint","color","shape","circle","square","dragon","monster","wizard","magic","spell","potion","sword","shield","castle","king",
"strawberry","blueberry","raspberry","blackberry","kiwi","lime","coconut","pineapple","melon","watermelon","papaya","guava","pomegranate","apricot","nectarine","fig","date","prune","raisin","cranberry",
"carrot","potato","tomato","onion","garlic","pepper","cucumber","lettuce","spinach","broccoli","cabbage","celery","corn","pea","bean","pumpkin","squash","eggplant","radish","beet",
"elephant","giraffe","zebra","monkey","gorilla","bear","deer","fox","frog","snake","lizard","turtle","whale","shark","dolphin","penguin","eagle","hawk","owl","duck",
"chicken","cow","pig","sheep","head","neck","shoulder","arm","elbow","hand","finger","thumb","chest","back","stomach","leg","knee","foot","toe","eye",
"ear","nose","mouth","tongue","tooth","hair","skin","bone","shirt","pants","dress","jacket","coat","hat","shoes","socks","gloves","scarf","belt","tie",
"skirt","sweater","hoodie","jeans","shorts","boot","sandal","slipper","lamp","clock","mirror","rug","towel","blanket","pillow","cup","plate","bowl","fork","knife",
"spoon","pan","pot","oven","fridge","washer","dryer","trash","printer","scanner","tablet","smartphone","speaker","headphone","microphone","webcam","drone","router","modem","cable",
"charger","plug","socket","wire","remote","joystick","trackpad","stylus","brown","bronze","teal","navy","lime","olive","maroon","beige","ivory","coral","magenta","cyan",
"lavender","turquoise","indigo","violet","cream","rose","tan","rust","push","pull","throw","catch","kick","hit","cut","copy","paste","search","find","replace",
"sort","filter","merge","split","lock","unlock","hide","show","zoom","rotate","flip","scale","drag","drop","swipe","scroll","tap","press","beautiful",
"ugly","rich","poor","clean","dirty","full","empty","noisy","quiet","busy","lazy","brave","afraid","gentle","rough","smooth","flat","round","straight","curved",
"broken","fixed","fresh","stale","thunder","lightning","fog","mist","hail","rainbow","flood","drought","volcano","earthquake","island","beach","coast","desert","jungle","swamp",
"cave","cliff","valley","hill","meadow","pond","stream","waterfall","canyon","glacier","tundra","prairie","marsh","reef","lagoon","delta","oasis","fjord","pasta","noodle",
"salad","sandwich","taco","burrito","sushi","steak","bacon","egg","butter","jam","honey","syrup","candy","cookie","chocolate","icecream","yogurt","cereal","tea","coffee",
"juice","soda","lemonade","smoothie","milkshake","beer","wine","cocktail","classroom","desk","chalkboard","whiteboard","marker","eraser","ruler","notebook","backpack","locker","bell","grade",
"report","test","quiz","project","assignment","diploma","degree","major","minor","one","two","three","four","five","six","seven","eight","nine","ten","monday",
"tuesday","wednesday","thursday","friday","saturday","sunday","january","february","march","april","may","june","july","august","september","october","november","december","mother","father",
"brother","sister","son","daughter","baby","child","parent","family","uncle","aunt","cousin","niece","nephew","grandfather","grandmother","husband","wife","grandparent","idea","problem",
"solution","question","answer","story","news","letter","number","art","science","math","history","language","sport","team","tool","vehicle","building","tunnel","tower","statue",
"monument","map","flag","sign","signal","shadow","dream","adventure","journey","treasure","secret","legend","myth","mystery","fantasy","metal","wood","stone","sand",
"dust","smoke","ash","lava","boolean","float","double","pointer","reference","void","return","break","continue","if","else","switch","case","default","try","catch",
"throw","finally","public","private","protected","static","virtual","abstract","interface","enum","struct","union","typedef","namespace","song","melody","rhythm","beat","note",
"chord","scale","instrument","guitar","piano","drum","violin","trumpet","flute","saxophone","band","orchestra","concert","album","track","football","soccer","basketball","baseball","tennis",
"hockey","golf","cricket","rugby","volleyball","swimming","running","cycling","boxing","wrestling","skiing","surfing","skateboard","climbing","fitness","breathe","sleep","eat","drink","talk",
"laugh","cry","smile","shout","whisper","love","hate","fear","joy","surprise","disgust","trust","hope","wish","regret","excitement","calm","pride","shame","atom",
"molecule","cell","dna","gene","virus","bacteria","particle","wave","experiment","laboratory","theory","hypothesis","formula","equation","graph","chart","diagram","microscope","telescope","solar",
"eclipse","constellation","nebula","asteroid","meteor","blackhole","universe","cosmic","lunar","martian","alien","spatula","whisk","grater","peeler","blender","toaster","microwave","kettle","teapot",
"mug","glass","bottle","sofa","couch","shelf","cabinet","drawer","wardrobe","dresser","stool","bench","soap","shampoo","conditioner","toothbrush","toothpaste","razor","comb","brush",
"lotion","perfume","helicopter","submarine","scooter","van","taxi","ambulance","firetruck","policecar","tractor","yacht","sailboat","doctor","nurse","engineer","scientist","artist","musician","actor",
"writer","chef","pilot","sailor","farmer","worker","boss","manager","director","president","queen","prince","princess","knight","judge","lawyer","officer","soldier","airport","station",
"hospital","library","museum","park","zoo","garden","stadium","mall","gym","temple","church","mosque","garage","warehouse","factory","lab","studio","office","hammer","screwdriver",
"wrench","pliers","saw","drill","axe","shovel","rake","hoe","ladder","tape","glue","screw","glass","plastic","rubber","leather","fabric","clay","cardboard","steel",
"iron","copper","aluminum","tin","freedom","justice","truth","lie","faith","destiny","fate","chance","luck","wisdom","courage","kindness","beauty","anger","honor","glory",
"victory","sorrow","defeat","add","subtract","multiply","divide","plus","minus","times","equal","greater","less","fraction","decimal","percent","root","cube","factor","prime",
"odd","even","sum"
    };

    int random_index = rand() % 1120;          //[0;1119]
    menu(words[random_index]);

    cout << "\n\n";
    return 0;
}