 #include<iostream>
 #include<fstream>
 #include<string.h>


 using namespace std;
 fstream f;
 int n;

 struct element
 {       int Z,g,p;
  char name[20],sym[4];
  float A,v;
  int temp;
 }R;

 

 void assign(int Z,int g,int p,char name[],char sym[],float a,float v,int t)
 {       R.Z=Z;
  R.g=g;
  R.p=p;
  strcpy(R.name,name);
  strcpy(R.sym,sym);
  R.A=a;
  R.v=v;
  R.temp=t;
 }


 void create()
 {   f.open("pt.dat",ios::out|ios::binary);
   for(n=1;n<119;++n)
    {if(n==1) assign(1,1,1,"Hydrogen","H",1.0079,1,1);
    else if(n==2) assign(2,18,1,"Helium","He",4.0026,0,1);
    else if(n==3) assign(3,1,2,"Lithium","Li",6.941,1,2);
    else if(n==4) assign(4,2,2,"Beryllium","Be",9.0122,2,2);
    else if(n==5) assign(5,13,2,"Boron","B",10.811,3,2);
    else if(n==6) assign(6,14,2,"Carbon","C",12.0107,4,2);
    else if(n==7) assign(7,15,2,"Nitrogen","N",14.0067,-3,2);
    else if(n==8) assign(8,16,2,"Oxygen","O",15.9994,-2,2);
    else if(n==9) assign(9,17,2,"Fluorine","F",18.9984,1,2);
    else if(n==10) assign(10,18,2,"Neon","Ne",20.1797,0,2);
    else if(n==11) assign(11,1,3,"Sodium","Na",22.9897,1,3);
    else if(n==12) assign(12,2,3,"Magnesium","Mg",24.305,2,3);
    else if(n==13) assign(13,13,3,"Aluminum","Al",26.9815,3,3);
    else if(n==14) assign(14,14,3,"Silicon","Si",28.0855,4,3);
    else if(n==15) assign(15,15,3,"Phosphorus","P",30.9738,5,3);
    else if(n==16) assign(16,16,3,"Sulfur","S",32.065,-2,3);
    else if(n==17) assign(17,17,3,"Chlorine","Cl",35.453,-1,3);
    else if(n==18) assign(18,18,3,"Argon","Ar",39.948,0,3);
    else if(n==19) assign(19,1,4,"Potassium","K",39.0983,1,4);
    else if(n==20) assign(20,2,4,"Calcium","Ca",40.078,2,4);
    else if(n==21) assign(21,3,4,"Scandium","Sc",44.9559,3,4);
    else if(n==22) assign(22,4,4,"Titanium","Ti",47.867,4,4);
    else if(n==23) assign(23,5,4,"Vanadium","V",50.9415,5,4);
    else if(n==24) assign(24,6,4,"Chromium","Cr",51.9961,6,4);
    else if(n==25) assign(25,7,4,"Manganese","Mn",54.938,4,4);
    else if(n==26) assign(26,8,4,"Iron","Fe",55.845,2,4);
    else if(n==27) assign(27,9,4,"Cobalt","Co",58.9332,2,4);
    else if(n==28) assign(28,10,4,"Nickel","Ni",58.6934,2,4);
    else if(n==29) assign(29,11,4,"Copper","Cu",63.546,2,4);
    else if(n==30) assign(30,12,4,"Zinc","Zn",65.39,2,4);
    else if(n==31) assign(31,13,4,"Gallium","Ga",69.723,3,4);
    else if(n==32) assign(32,14,4,"Germanium","Ge",72.64,3,4);
    else if(n==33) assign(33,15,4,"Arsenic","As",74.9216,5,4);
    else if(n==34) assign(34,16,4,"Selenium","Se",78.96,4,4);
    else if(n==35) assign(35,17,4,"Bromine","Br",79.904,-1,4);
    else if(n==36) assign(36,18,4,"Krypton","Kr",83.8,2,4);
    else if(n==37) assign(37,1,5,"Rubidium","Rb",85.4678,1,5);
    else if(n==38) assign(38,2,5,"Strontium","Sr",87.62,2,5);
    else if(n==39) assign(39,3,5,"Yttrium","Y",88.9059,3,5);
    else if(n==40) assign(40,4,5,"Zirconium","Zr",91.224,4,5);
    else if(n==41) assign(41,5,5,"Niobium","Nb",92.9064,5,5);
    else if(n==42) assign(42,6,5,"Molybdenum","Mo",95.94,6,5);
    else if(n==43) assign(43,7,5,"Technetium","Tc",98,4,5);
    else if(n==44) assign(44,8,5,"Ruthenium","Ru",101.07,4,5);
    else if(n==45) assign(45,9,5,"Rhodium","Rh",102.9055,3,5);
    else if(n==46) assign(46,10,5,"Palladium","Pd",106.42,2,5);
    else if(n==47) assign(47,11,5,"Silver","Ag",107.8682,1,5);
    else if(n==48) assign(48,12,5,"Cadmium","Cd",112.411,2,5);
    else if(n==49) assign(49,13,5,"Indium","In",114.818,3,5);
    else if(n==50) assign(50,14,5,"Tin","Sn",118.71,2,5);
    else if(n==51) assign(51,15,5,"Antimony","Sb",121.76,2,5);
    else if(n==52) assign(52,16,5,"Tellurium","Te",127.6,2,5);
    else if(n==53) assign(53,17,5,"Iodine","I",126.9045,-1,5);
    else if(n==54) assign(54,18,5,"Xenon","Xe",131.293,6,5);
    else if(n==55) assign(55,1,6,"Cesium","Cs",132.9055,1,6);
    else if(n==56) assign(56,2,6,"Barium","Ba",137.327,2,6);
    else if(n==57) assign(57,3,6,"Lanthanum","La",138.9055,3,6);
    else if(n==58) assign(58,3,6,"Cerium","Ce",140.116,4,8);
    else if(n==59) assign(59,3,6,"Praseodymium","Pr",140.9077,2,8);
    else if(n==60) assign(60,3,6,"Neodymium","Nd",144.24,3,8);
    else if(n==61) assign(61,3,6,"Promethium","Pm",145,3,8);
    else if(n==62) assign(62,3,6,"Samarium","Sm",150.36,2,8);
    else if(n==63) assign(63,3,6,"Europium","Eu",151.964,2,8);
    else if(n==64) assign(64,3,6,"Gadolinium","Gd",157.25,1,8);
    else if(n==65) assign(65,3,6,"Terbium","Tb",158.9253,3,8);
    else if(n==66) assign(66,3,6,"Dysprosium","Dy",162.5,3,8);
    else if(n==67) assign(67,3,6,"Holmium","Ho",164.9303,3,8);
    else if(n==68) assign(68,3,6,"Erbium","Er",167.259,3,8);
    else if(n==69) assign(69,3,6,"Thulium","Tm",168.9342,3,8);
    else if(n==70) assign(70,3,6,"Ytterbium","Yb",173.04,3,8);
    else if(n==71) assign(71,3,6,"Lutetium","Lu",174.967,3,8);
    else if(n==72) assign(72,4,6,"Hafnium","Hf",178.49,4,6);
    else if(n==73) assign(73,5,6,"Tantalum","Ta",180.9479,5,6);
    else if(n==74) assign(74,6,6,"Tungsten","W",183.84,4,6);
    else if(n==75) assign(75,7,6,"Rhenium","Re",186.207,4,6);
    else if(n==76) assign(76,8,6,"Osmium","Os",190.23,6,6);
    else if(n==77) assign(77,9,6,"Iridium","Ir",192.217,1,6);
    else if(n==78) assign(78,10,6,"Platinum","Pt",195.078,2,6);
    else if(n==79) assign(79,11,6,"Gold","Au",196.9665,1,6);
    else if(n==80) assign(80,12,6,"Mercury","Hg",200.59,2,6);
    else if(n==81) assign(81,13,6,"Thallium","Tl",204.3833,1,6);
    else if(n==82) assign(82,14,6,"Lead","Pb",207.2,2,6);
    else if(n==83) assign(83,15,6,"Bismuth","Bi",208.9804,3,6);
    else if(n==84) assign(84,16,6,"Polonium","Po",209,2,6);
    else if(n==85) assign(85,17,6,"Astatine","At",210,1,6);
    else if(n==86) assign(86,18,6,"Radon","Rn",222,2,6);
    else if(n==87) assign(87,1,7,"Francium","Fr",223,1,7);
    else if(n==88) assign(88,2,7,"Radium","Ra",226,2,7);
    else if(n==89) assign(89,3,7,"Actinium","Ac",227,3,7);
    else if(n==90) assign(90,3,7,"Thorium","Th",232.0381,4,9);
    else if(n==91) assign(91,3,7,"Protactinium","Pa",231.0359,5,9);
    else if(n==92) assign(92,3,7,"Uranium","U",238.0289,6,9);
    else if(n==93) assign(93,3,7,"Neptunium","Np",237,3,9);
    else if(n==94) assign(94,3,7,"Plutonium","Pu",244,4,9);
    else if(n==95) assign(95,3,7,"Americium","Am",243,3,9);
    else if(n==96) assign(96,3,7,"Curium","Cm",247,3,9);
    else if(n==97) assign(97,3,7,"Berkelium","Bk",247,3,9);
    else if(n==98) assign(98,3,7,"Californium","Cf",251,2,9);
    else if(n==99) assign(99,3,7,"Einsteinium","Es",252,3,9);
    else if(n==100) assign(100,3,7,"Fermium","Fm",257,3,9);
    else if(n==101) assign(101,3,7,"Mendelevium","Md",258,3,9);
    else if(n==102) assign(102,3,7,"Nobelium","No",259,2,9);
    else if(n==103) assign(103,3,7,"Lawrencium","Lr",262,3,9);
    else if(n==104) assign(104,4,7,"Rutherfordium","Rf",267,4,7);
    else if(n==105) assign(105,5,7,"Dubnium","Db",268,5,7);
    else if(n==106) assign(106,6,7,"Seaborgium","Sg",269,6,7);
    else if(n==107) assign(107,7,7,"Bohrium","Bh",270,7,7);
    else if(n==108) assign(108,8,7,"Hassium","Hs",269,8,7);
    else if(n==109) assign(109,9,7,"Meitnerium","Mt",278,3,7);
    else if(n==110) assign(110,10,7,"Darmstadtium","Ds",281,6,7);
    else if(n==111) assign(111,11,7,"Roentgenium","Rg",281,3,7);
    else if(n==112) assign(112,12,7,"Ununbium","Uub",285,2,7); 
    else if(n==113) assign(113,13,7,"Ununtrium","Uut",286,1,7);
    else if(n==114) assign(114,14,7,"Ununquadium","Uuq",289,2,7);
    else if(n==115) assign(115,15,7,"Ununpentium","Uup",289,1,7);
    else if(n==116) assign(116,16,7,"Ununhexium","Uuh",293,2,7);
    else if(n==117) assign(117,17,7,"Ununseptium","Uus",294,1,7);
    else if(n==118) assign(118,18,7,"Ununoctium","Uuo",294,2,7);
   f.write((char*)&R,sizeof(R));
  }
 f.close();
 }


 void table()
 {       f.open("pt.dat",ios::in|ios::binary);
  f.read((char*)&R,sizeof(R));
  cout<<"\n\t\tThe complete periodic table is given below:"<<"\n\n\n";
  for (int i=1; i<10; i++)
   {cout<<" ";
   for (int j=1; j<19; j++)
    { if (j==R.g || i==R.temp)
                                        {if (j==1 && (i==8 || i==9)) cout<<"\t\t"<<R.sym<<"\t";     

                                  else cout<<R.sym<<"\t";
     if (i==1 && j==1)
      cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
      
     if ((i==2||i==3)&&j==2)
      cout<<"\t\t\t\t\t\t\t\t\t\t";
      
     if ((i==6||i==7) && j==3) {f.seekg(14*sizeof(R),ios::cur);}
     if (i==7 && j==18) {f.seekg(-61*sizeof(R),ios::cur);cout<<"\n\n";}
     if (i==8 && j==14) {f.seekg(18*sizeof(R),ios::cur);}
     f.read((char*)&R,sizeof(R));
     }
    else cout<<"\t";
    }
   cout<<"\n\n";
   }
                     f.close();
 }
 

 void det()
 {       f.open("pt.dat",ios::in|ios::binary);
  f.seekg(0);
                cout<<"\n\t\tEnter the atomic number of an element to know its details (1-118) ";
  cin>>n;
                while(n<1||n>118)
                 { cout<<"\t\tInvalid atomic number!!!\n\tEnter any number between 1 and 118 again....";
                   cin>>n; }
  while(f)
   {f.read((char*)&R,sizeof(R));
   if(n==R.Z) break;
   }
    cout<<"\n\tAtomic no. : \t"<<R.Z<<"\n\tGroup : \t"<<R.g
    <<"\n\tPeriod : \t"<<R.p<<"\n\tName : \t\t"<<R.name<<"\n\tSymbol : \t"<<R.sym
                  <<"\n\tAtomic mass : \t"<<R.A<<"\n\tValency : \t"<<R.v<<"\n\n";

    f.close();
 }

 
 int main(void)
 {       create();
                char c;
                cout<<"\n\n\t\t\t\t\t*** PERIODIC TABLE ***\n\t\t\t\t\t\t\t"
                    <<"\t- C++ Project done by N. Mythili\n\n\n\t\tWhat do you want to do?\n\n\t\t"
                    <<"1. Display details of an element\n\t\t"
                    <<"2. Display the complete periodic table";
                do
                 { cout<<"\n\n\t\tEnter your choice (1/2)\t";
                   cin>>c;
                   if(c=='1') det();
                   else if(c=='2') table();
                   cout<<"\n\t\tDo you want to continue? (y/n)\t";
                   cin>>c;
                 
                 }while(c=='y'||c=='Y'); 
  
  }
