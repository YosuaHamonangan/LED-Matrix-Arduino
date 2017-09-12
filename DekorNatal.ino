#define BARIS 24
#define KOLOM 22
#define CLK_STORAGE 2
#define CLK_KOLOM 3
#define CLK_BARIS 4
#define DATA_BARIS 5

int baris=7-1;
bool kordinat1[24][22], *kordinat2[28][10];

void setup() {
  konversi();
  
  for(int a=0;a<BARIS;a++)
  {
    for(int b=0;b<KOLOM;b++)
    {
      kordinat1[a][b]=0;
    }
  }
  
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 50000;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS10);  
  TIMSK1 |= (1 << OCIE1A);

  sei();

  pinMode(CLK_STORAGE,OUTPUT);
  pinMode(CLK_KOLOM,OUTPUT);
  pinMode(CLK_BARIS,OUTPUT);
  pinMode(DATA_BARIS,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  
  resetArray();
  
  digitalWrite(CLK_STORAGE,0);
  digitalWrite(CLK_KOLOM,0);
  digitalWrite(CLK_BARIS,0);
  digitalWrite(DATA_BARIS,0);
  digitalWrite(6,0);
  
  for(int a=0;a<8;a++)
  {
    digitalWrite(CLK_KOLOM,1);
    digitalWrite(CLK_KOLOM,0);
    digitalWrite(CLK_BARIS,1);
    digitalWrite(CLK_BARIS,0);
  }
  
  digitalWrite(DATA_BARIS,1);
  digitalWrite(CLK_BARIS,1);
  digitalWrite(CLK_BARIS,0);
  
  digitalWrite(CLK_STORAGE,1);
  digitalWrite(CLK_STORAGE,0);


}

void resetArray()
{  
  for(int a=0;a<BARIS;a++)
  {
    for(int b=0;b<KOLOM;b++)
    {
      kordinat1[a][b]=0;
    }
  }
}

void idupinsemua()
{  
  for(int a=0;a<BARIS;a++)
  {
    for(int b=0;b<KOLOM;b++)
    {
      kordinat1[a][b]=1;
    }
  }
}

ISR(TIMER1_COMPA_vect){
  
  //shift reg baris
  if(baris==7)
  {
    digitalWrite(DATA_BARIS,1);
    baris=0;
  }
  else
  {
    digitalWrite(DATA_BARIS,0);
    baris++;
  }
  digitalWrite(CLK_BARIS,1);
  digitalWrite(CLK_BARIS,0);
  
  //shift reg 1
  for(int kolom=7;kolom>=0;kolom--)
  {
    digitalWrite(6,kordinat1[baris][kolom]);
    digitalWrite(7,kordinat1[baris][kolom+8]);
    digitalWrite(8,kordinat1[baris][kolom+16]);
    digitalWrite(9,kordinat1[baris+8][kolom]);
    digitalWrite(10,kordinat1[baris+8][kolom+8]);
    digitalWrite(11,kordinat1[baris+8][kolom+16]);
    digitalWrite(12,kordinat1[baris+16][kolom]);
    digitalWrite(13,kordinat1[baris+16][kolom+8]);
    digitalWrite(14,kordinat1[baris+16][kolom+16]);
    
    digitalWrite(CLK_KOLOM,1);
    digitalWrite(CLK_KOLOM,0);
  }
  digitalWrite(CLK_STORAGE,1);
  digitalWrite(CLK_STORAGE,0);
}

void konversi()
{
  kordinat2[0][0] = &kordinat1[0][21];
  kordinat2[1][0] = &kordinat1[1][21];
  kordinat2[2][0] = &kordinat1[2][21];
  kordinat2[3][0] = &kordinat1[3][21];
  kordinat2[4][0] = &kordinat1[0][10];
  kordinat2[5][0] = &kordinat1[1][10];
  kordinat2[6][0] = &kordinat1[2][10];
  kordinat2[7][0] = &kordinat1[3][10];
  kordinat2[8][0] = &kordinat1[4][11];
  kordinat2[9][0] = &kordinat1[5][11];
  kordinat2[10][0] = &kordinat1[6][11];
  kordinat2[11][0] = &kordinat1[7][11];
  kordinat2[12][0] = &kordinat1[8][12];
  kordinat2[13][0] = &kordinat1[9][12];
  kordinat2[14][0] = &kordinat1[10][12];
  kordinat2[15][0] = &kordinat1[11][12];
  kordinat2[16][0] = &kordinat1[12][13];
  kordinat2[17][0] = &kordinat1[13][13];
  kordinat2[18][0] = &kordinat1[14][13];
  kordinat2[19][0] = &kordinat1[15][13];
  kordinat2[20][0] = &kordinat1[16][14];
  kordinat2[21][0] = &kordinat1[17][14];
  kordinat2[22][0] = &kordinat1[18][14];
  kordinat2[23][0] = &kordinat1[19][14];
  kordinat2[24][0] = &kordinat1[20][15];
  kordinat2[25][0] = &kordinat1[21][15];
  kordinat2[26][0] = &kordinat1[22][15];
  kordinat2[27][0] = &kordinat1[23][15];
  
  kordinat2[0][1] = &kordinat1[0][20];
  kordinat2[1][1] = &kordinat1[1][20];
  kordinat2[2][1] = &kordinat1[2][20];
  kordinat2[3][1] = &kordinat1[3][20];
  kordinat2[4][1] = &kordinat1[0][9];
  kordinat2[5][1] = &kordinat1[1][9];
  kordinat2[6][1] = &kordinat1[2][9];
  kordinat2[7][1] = &kordinat1[3][9];
  kordinat2[8][1] = &kordinat1[4][10];
  kordinat2[9][1] = &kordinat1[5][10];
  kordinat2[10][1] = &kordinat1[6][10];
  kordinat2[11][1] = &kordinat1[7][10];
  kordinat2[12][1] = &kordinat1[8][11];
  kordinat2[13][1] = &kordinat1[9][11];
  kordinat2[14][1] = &kordinat1[10][11];
  kordinat2[15][1] = &kordinat1[11][11];
  kordinat2[16][1] = &kordinat1[12][12];
  kordinat2[17][1] = &kordinat1[13][12];
  kordinat2[18][1] = &kordinat1[14][12];
  kordinat2[19][1] = &kordinat1[15][12];
  kordinat2[20][1] = &kordinat1[16][13];
  kordinat2[21][1] = &kordinat1[17][13];
  kordinat2[22][1] = &kordinat1[18][13];
  kordinat2[23][1] = &kordinat1[19][13];
  kordinat2[24][1] = &kordinat1[20][14];
  kordinat2[25][1] = &kordinat1[21][14];
  kordinat2[26][1] = &kordinat1[22][14];
  kordinat2[27][1] = &kordinat1[23][14];

  kordinat2[0][2] = &kordinat1[0][19];
  kordinat2[1][2] = &kordinat1[1][19];
  kordinat2[2][2] = &kordinat1[2][19];
  kordinat2[3][2] = &kordinat1[3][19];
  kordinat2[4][2] = &kordinat1[0][8];
  kordinat2[5][2] = &kordinat1[1][8];
  kordinat2[6][2] = &kordinat1[2][8];
  kordinat2[7][2] = &kordinat1[3][8];
  kordinat2[8][2] = &kordinat1[4][9];
  kordinat2[9][2] = &kordinat1[5][9];
  kordinat2[10][2] = &kordinat1[6][9];
  kordinat2[11][2] = &kordinat1[7][9];
  kordinat2[12][2] = &kordinat1[8][10];
  kordinat2[13][2] = &kordinat1[9][10];
  kordinat2[14][2] = &kordinat1[10][10];
  kordinat2[15][2] = &kordinat1[11][10];
  kordinat2[16][2] = &kordinat1[12][11];
  kordinat2[17][2] = &kordinat1[13][11];
  kordinat2[18][2] = &kordinat1[14][11];
  kordinat2[19][2] = &kordinat1[15][11];
  kordinat2[20][2] = &kordinat1[16][12];
  kordinat2[21][2] = &kordinat1[17][12];
  kordinat2[22][2] = &kordinat1[18][12];
  kordinat2[23][2] = &kordinat1[19][12];
  kordinat2[24][2] = &kordinat1[20][13];
  kordinat2[25][2] = &kordinat1[21][13];
  kordinat2[26][2] = &kordinat1[22][13];
  kordinat2[27][2] = &kordinat1[23][13];
  
  kordinat2[0][3] = &kordinat1[0][18];
  kordinat2[1][3] = &kordinat1[1][18];
  kordinat2[2][3] = &kordinat1[2][18];
  kordinat2[3][3] = &kordinat1[3][18];
  kordinat2[4][3] = &kordinat1[0][7];
  kordinat2[5][3] = &kordinat1[1][7];
  kordinat2[6][3] = &kordinat1[2][7];
  kordinat2[7][3] = &kordinat1[3][7];
  kordinat2[8][3] = &kordinat1[4][8];
  kordinat2[9][3] = &kordinat1[5][8];
  kordinat2[10][3] = &kordinat1[6][8];
  kordinat2[11][3] = &kordinat1[7][8];
  kordinat2[12][3] = &kordinat1[8][9];
  kordinat2[13][3] = &kordinat1[9][9];
  kordinat2[14][3] = &kordinat1[10][9];
  kordinat2[15][3] = &kordinat1[11][9];
  kordinat2[16][3] = &kordinat1[12][10];
  kordinat2[17][3] = &kordinat1[13][10];
  kordinat2[18][3] = &kordinat1[14][10];
  kordinat2[19][3] = &kordinat1[15][10];
  kordinat2[20][3] = &kordinat1[16][11];
  kordinat2[21][3] = &kordinat1[17][11];
  kordinat2[22][3] = &kordinat1[18][11];
  kordinat2[23][3] = &kordinat1[19][11];
  kordinat2[24][3] = &kordinat1[20][12];
  kordinat2[25][3] = &kordinat1[21][12];
  kordinat2[26][3] = &kordinat1[22][12];
  kordinat2[27][3] = &kordinat1[23][12];
  
  kordinat2[0][4] = &kordinat1[0][17];
  kordinat2[1][4] = &kordinat1[1][17];
  kordinat2[2][4] = &kordinat1[2][17];
  kordinat2[3][4] = &kordinat1[3][17];
  kordinat2[4][4] = &kordinat1[0][6];
  kordinat2[5][4] = &kordinat1[1][6];
  kordinat2[6][4] = &kordinat1[2][6];
  kordinat2[7][4] = &kordinat1[3][6];
  kordinat2[8][4] = &kordinat1[4][7];
  kordinat2[9][4] = &kordinat1[5][7];
  kordinat2[10][4] = &kordinat1[6][7];
  kordinat2[11][4] = &kordinat1[7][7];
  kordinat2[12][4] = &kordinat1[8][8];
  kordinat2[13][4] = &kordinat1[9][8];
  kordinat2[14][4] = &kordinat1[10][8];
  kordinat2[15][4] = &kordinat1[11][8];
  kordinat2[16][4] = &kordinat1[12][9];
  kordinat2[17][4] = &kordinat1[13][9];
  kordinat2[18][4] = &kordinat1[14][9];
  kordinat2[19][4] = &kordinat1[15][9];
  kordinat2[20][4] = &kordinat1[16][10];
  kordinat2[21][4] = &kordinat1[17][10];
  kordinat2[22][4] = &kordinat1[18][10];
  kordinat2[23][4] = &kordinat1[19][10];
  kordinat2[24][4] = &kordinat1[20][11];
  kordinat2[25][4] = &kordinat1[21][11];
  kordinat2[26][4] = &kordinat1[22][11];
  kordinat2[27][4] = &kordinat1[23][11];
  
  kordinat2[0][5] = &kordinat1[0][16];
  kordinat2[1][5] = &kordinat1[1][16];
  kordinat2[2][5] = &kordinat1[2][16];
  kordinat2[3][5] = &kordinat1[3][16];
  kordinat2[4][5] = &kordinat1[0][5];
  kordinat2[5][5] = &kordinat1[1][5];
  kordinat2[6][5] = &kordinat1[2][5];
  kordinat2[7][5] = &kordinat1[3][5];
  kordinat2[8][5] = &kordinat1[4][6];
  kordinat2[9][5] = &kordinat1[5][6];
  kordinat2[10][5] = &kordinat1[6][6];
  kordinat2[11][5] = &kordinat1[7][6];
  kordinat2[12][5] = &kordinat1[8][7];
  kordinat2[13][5] = &kordinat1[9][7];
  kordinat2[14][5] = &kordinat1[10][7];
  kordinat2[15][5] = &kordinat1[11][7];
  kordinat2[16][5] = &kordinat1[12][8];
  kordinat2[17][5] = &kordinat1[13][8];
  kordinat2[18][5] = &kordinat1[14][8];
  kordinat2[19][5] = &kordinat1[15][8];
  kordinat2[20][5] = &kordinat1[16][9];
  kordinat2[21][5] = &kordinat1[17][9];
  kordinat2[22][5] = &kordinat1[18][9];
  kordinat2[23][5] = &kordinat1[19][9];
  kordinat2[24][5] = &kordinat1[20][10];
  kordinat2[25][5] = &kordinat1[21][10];
  kordinat2[26][5] = &kordinat1[22][10];
  kordinat2[27][5] = &kordinat1[23][10];

  kordinat2[0][6] = &kordinat1[0][15];
  kordinat2[1][6] = &kordinat1[1][15];
  kordinat2[2][6] = &kordinat1[2][15];
  kordinat2[3][6] = &kordinat1[3][15];
  kordinat2[4][6] = &kordinat1[0][4];
  kordinat2[5][6] = &kordinat1[1][4];
  kordinat2[6][6] = &kordinat1[2][4];
  kordinat2[7][6] = &kordinat1[3][4];
  kordinat2[8][6] = &kordinat1[4][5];
  kordinat2[9][6] = &kordinat1[5][5];
  kordinat2[10][6] = &kordinat1[6][5];
  kordinat2[11][6] = &kordinat1[7][5];
  kordinat2[12][6] = &kordinat1[8][6];
  kordinat2[13][6] = &kordinat1[9][6];
  kordinat2[14][6] = &kordinat1[10][6];
  kordinat2[15][6] = &kordinat1[11][6];
  kordinat2[16][6] = &kordinat1[12][7];
  kordinat2[17][6] = &kordinat1[13][7];
  kordinat2[18][6] = &kordinat1[14][7];
  kordinat2[19][6] = &kordinat1[15][7];
  kordinat2[20][6] = &kordinat1[16][8];
  kordinat2[21][6] = &kordinat1[17][8];
  kordinat2[22][6] = &kordinat1[18][8];
  kordinat2[23][6] = &kordinat1[19][8];
  kordinat2[24][6] = &kordinat1[20][9];
  kordinat2[25][6] = &kordinat1[21][9];
  kordinat2[26][6] = &kordinat1[22][9];
  kordinat2[27][6] = &kordinat1[23][9];
  
  kordinat2[0][7] = &kordinat1[0][14];
  kordinat2[1][7] = &kordinat1[1][14];
  kordinat2[2][7] = &kordinat1[2][14];
  kordinat2[3][7] = &kordinat1[3][14];
  kordinat2[4][7] = &kordinat1[0][3];
  kordinat2[5][7] = &kordinat1[1][3];
  kordinat2[6][7] = &kordinat1[2][3];
  kordinat2[7][7] = &kordinat1[3][3];
  kordinat2[8][7] = &kordinat1[4][4];
  kordinat2[9][7] = &kordinat1[5][4];
  kordinat2[10][7] = &kordinat1[6][4];
  kordinat2[11][7] = &kordinat1[7][4];
  kordinat2[12][7] = &kordinat1[8][5];
  kordinat2[13][7] = &kordinat1[9][5];
  kordinat2[14][7] = &kordinat1[10][5];
  kordinat2[15][7] = &kordinat1[11][5];
  kordinat2[16][7] = &kordinat1[12][6];
  kordinat2[17][7] = &kordinat1[13][6];
  kordinat2[18][7] = &kordinat1[14][6];
  kordinat2[19][7] = &kordinat1[15][6];
  kordinat2[20][7] = &kordinat1[16][7];
  kordinat2[21][7] = &kordinat1[17][7];
  kordinat2[22][7] = &kordinat1[18][7];
  kordinat2[23][7] = &kordinat1[19][7];
  kordinat2[24][7] = &kordinat1[20][8];
  kordinat2[25][7] = &kordinat1[21][8];
  kordinat2[26][7] = &kordinat1[22][8];
  kordinat2[27][7] = &kordinat1[23][8];
  
  kordinat2[0][8] = &kordinat1[0][13];
  kordinat2[1][8] = &kordinat1[1][13];
  kordinat2[2][8] = &kordinat1[2][13];
  kordinat2[3][8] = &kordinat1[3][13];
  kordinat2[4][8] = &kordinat1[0][2];
  kordinat2[5][8] = &kordinat1[1][2];
  kordinat2[6][8] = &kordinat1[2][2];
  kordinat2[7][8] = &kordinat1[3][2];
  kordinat2[8][8] = &kordinat1[4][3];
  kordinat2[9][8] = &kordinat1[5][3];
  kordinat2[10][8] = &kordinat1[6][3];
  kordinat2[11][8] = &kordinat1[7][3];
  kordinat2[12][8] = &kordinat1[8][4];
  kordinat2[13][8] = &kordinat1[9][4];
  kordinat2[14][8] = &kordinat1[10][4];
  kordinat2[15][8] = &kordinat1[11][4];
  kordinat2[16][8] = &kordinat1[12][5];
  kordinat2[17][8] = &kordinat1[13][5];
  kordinat2[18][8] = &kordinat1[14][5];
  kordinat2[19][8] = &kordinat1[15][5];
  kordinat2[20][8] = &kordinat1[16][6];
  kordinat2[21][8] = &kordinat1[17][6];
  kordinat2[22][8] = &kordinat1[18][6];
  kordinat2[23][8] = &kordinat1[19][6];
  kordinat2[24][8] = &kordinat1[20][7];
  kordinat2[25][8] = &kordinat1[21][7];
  kordinat2[26][8] = &kordinat1[22][7];
  kordinat2[27][8] = &kordinat1[23][7];

  kordinat2[0][9] = &kordinat1[0][12];
  kordinat2[1][9] = &kordinat1[1][12];
  kordinat2[2][9] = &kordinat1[2][12];
  kordinat2[3][9] = &kordinat1[3][12];
  kordinat2[4][9] = &kordinat1[0][1];
  kordinat2[5][9] = &kordinat1[1][1];
  kordinat2[6][9] = &kordinat1[2][1];
  kordinat2[7][9] = &kordinat1[3][1];
  kordinat2[8][9] = &kordinat1[4][2];
  kordinat2[9][9] = &kordinat1[5][2];
  kordinat2[10][9] = &kordinat1[6][2];
  kordinat2[11][9] = &kordinat1[7][2];
  kordinat2[12][9] = &kordinat1[8][3];
  kordinat2[13][9] = &kordinat1[9][3];
  kordinat2[14][9] = &kordinat1[10][3];
  kordinat2[15][9] = &kordinat1[11][3];
  kordinat2[16][9] = &kordinat1[12][4];
  kordinat2[17][9] = &kordinat1[13][4];
  kordinat2[18][9] = &kordinat1[14][4];
  kordinat2[19][9] = &kordinat1[15][4];
  kordinat2[20][9] = &kordinat1[16][5];
  kordinat2[21][9] = &kordinat1[17][5];
  kordinat2[22][9] = &kordinat1[18][5];
  kordinat2[23][9] = &kordinat1[19][5];
  kordinat2[24][9] = &kordinat1[20][6];
  kordinat2[25][9] = &kordinat1[21][6];
  kordinat2[26][9] = &kordinat1[22][6];
  kordinat2[27][9] = &kordinat1[23][6];
}

void tampilkan(int baris, int kolom)
{
  for(int a;a<10;a++)
  {
    *kordinat2[baris][a]=kolom&1;
    kolom=kolom>>1;
  }
}

void loop() 
{
  resetArray();

int b;
for(int a=0;a<22;a++)
{
  b=a%2;
  if(b<4) 
  {
    for(int c=0;c<24;c+=4)
    {
      kordinat1[c+b][a]=1;
    }
  }
  else
  {
    for(int c=0;c<24;c+=4)
    {
      kordinat1[c+2-b][a]=1;
    }
  }
for(int a=0;a<3;a++)
  {
    on(0+a,0);
    on(1+a,0);
    on(0+a,11);
    on(1+a,11);
    
    on(0+a,21);
    on(1+a,21);
    on(0+a,12);
    on(1+a,12);
    
    on(4+a,0);
    on(5+a,0);
    on(4+a,13);
    on(5+a,13);
    
    on(4+a,21);
    on(5+a,21);
    on(4+a,14);
    on(5+a,14);
    
    on(8+a,0);
    on(9+a,0);
    on(8+a,15);
    on(9+a,15);
    
    on(8+a,21);
    on(9+a,21);
    on(8+a,16);
    on(9+a,16);
    
    on(12+a,0);
    on(13+a,0);
    on(12+a,17);
    on(13+a,17);
    
    on(12+a,21);
    on(13+a,21);
    on(12+a,18);
    on(13+a,18);
    
    on(16+a,0);
    on(17+a,0);
    on(16+a,19);
    on(17+a,19);
    
    on(16+a,21);
    on(17+a,21);
    on(16+a,20);
    on(17+a,20);
    
    on(20+a,0);
    on(21+a,0);
    on(20+a,21);
    on(21+a,21);
   
    delay(100);
    off(0+a,0);
    off(1+a,0);
    off(0+a,11);
    off(1+a,11);
    
    off(0+a,21);
    off(1+a,21);
    off(0+a,12);
    off(1+a,12);
    
    off(4+a,0);
    off(5+a,0);
    off(4+a,13);
    off(5+a,13);
    
    off(4+a,21);
    off(5+a,21);
    off(4+a,14);
    off(5+a,14);
    
    off(8+a,0);
    off(9+a,0);
    off(8+a,15);
    off(9+a,15);
    
    off(8+a,21);
    off(9+a,21);
    off(8+a,16);
    off(9+a,16);
    
    off(12+a,0);
    off(13+a,0);
    off(12+a,17);
    off(13+a,17);
    
    off(12+a,21);
    off(13+a,21);
    off(12+a,18);
    off(13+a,18);
    
    off(16+a,0);
    off(17+a,0);
    off(16+a,19);
    off(17+a,19);
    
    off(16+a,21);
    off(17+a,21);
    off(16+a,20);
    off(17+a,20);
    
    off(20+a,0);
    off(21+a,0);
    off(20+a,21);
    off(21+a,21);
  }
  
  on(0,0);
  on(3,0);
  on(0,11);
  on(3,11);
  
  on(0,21);
  on(3,21);
  on(0,12);
  on(3,12);
  
  on(4,0);
  on(7,0);
  on(4,13);
  on(7,13);
  
  on(4,21);
  on(7,21);
  on(4,14);
  on(7,14);
  
  on(8,0);
  on(11,0);
  on(8,15);
  on(11,15);
  
  on(8,21);
  on(11,21);
  on(8,16);
  on(11,16);
  
  on(12,0);
  on(15,0);
  on(12,17);
  on(15,17);
  
  on(12,21);
  on(15,21);
  on(12,18);
  on(15,18);
  
  on(16,0);
  on(19,0);
  on(16,19);
  on(19,19);
  
  on(19,21);
  on(19,20);
  
  on(20,0);
  on(23,0);
  on(20,21);
  on(23,21);
 
  delay(100);
  off(0,0);
  off(3,0);
  off(0,11);
  off(3,11);
  
  off(0,21);
  off(3,21);
  off(0,12);
  off(3,12);
  
  off(4,0);
  off(7,0);
  off(4,13);
  off(7,13);
  
  off(4,21);
  off(7,21);
  off(4,14);
  off(7,14);
  
  off(8,0);
  off(11,0);
  off(8,15);
  off(11,15);
  
  off(8,21);
  off(11,21);
  off(8,16);
  off(11,16);
  
  off(12,0);
  off(15,0);
  off(12,17);
  off(15,17);
  
  off(12,21);
  off(15,21);
  off(12,18);
  off(15,18);
  
  off(16,0);
  off(19,0);
  off(16,19);
  off(19,19);
  
  off(19,21);
  off(19,20);
  
  off(20,0);
  off(23,0);
  off(20,21);
  off(23,21);
}    
delay(500);

//I
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//IB
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 96);
tampilkan(5, 160);
tampilkan(6, 96);
tampilkan(7, 160);
tampilkan(8, 96);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//IBA
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 96);
tampilkan(5, 160);
tampilkan(6, 96);
tampilkan(7, 160);
tampilkan(8, 96);
tampilkan(9, 14);
tampilkan(10, 10);
tampilkan(11, 14);
tampilkan(12, 10);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//IBAD
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 96);
tampilkan(5, 160);
tampilkan(6, 96);
tampilkan(7, 160);
tampilkan(8, 96);
tampilkan(9, 14);
tampilkan(10, 10);
tampilkan(11, 14);
tampilkan(12, 10);
tampilkan(13, 96);
tampilkan(14, 160);
tampilkan(15, 160);
tampilkan(16, 96);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//IBADA
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 96);
tampilkan(5, 160);
tampilkan(6, 96);
tampilkan(7, 160);
tampilkan(8, 96);
tampilkan(9, 14);
tampilkan(10, 10);
tampilkan(11, 14);
tampilkan(12, 10);
tampilkan(13, 96);
tampilkan(14, 160);
tampilkan(15, 160);
tampilkan(16, 96);
tampilkan(17, 14);
tampilkan(18, 10);
tampilkan(19, 14);
tampilkan(20, 10);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//IBADAH
tampilkan(0, 14);
tampilkan(1, 4);
tampilkan(2, 4);
tampilkan(3, 14);
tampilkan(4, 96);
tampilkan(5, 160);
tampilkan(6, 96);
tampilkan(7, 160);
tampilkan(8, 96);
tampilkan(9, 14);
tampilkan(10, 10);
tampilkan(11, 14);
tampilkan(12, 10);
tampilkan(13, 96);
tampilkan(14, 160);
tampilkan(15, 160);
tampilkan(16, 96);
tampilkan(17, 14);
tampilkan(18, 10);
tampilkan(19, 14);
tampilkan(20, 10);
tampilkan(21, 160);
tampilkan(22, 160);
tampilkan(23, 224);
tampilkan(24, 160);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);


//N
tampilkan(0, 17);
tampilkan(1, 19);
tampilkan(2, 21);
tampilkan(3, 25);
tampilkan(4, 17);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//NA
tampilkan(0, 17);
tampilkan(1, 19);
tampilkan(2, 21);
tampilkan(3, 25);
tampilkan(4, 17);
tampilkan(5, 960);
tampilkan(6, 576);
tampilkan(7, 960);
tampilkan(8, 576);
tampilkan(9, 576);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//NAT
tampilkan(0, 17);
tampilkan(1, 19);
tampilkan(2, 21);
tampilkan(3, 25);
tampilkan(4, 17);
tampilkan(5, 960);
tampilkan(6, 576);
tampilkan(7, 960);
tampilkan(8, 576);
tampilkan(9, 576);
tampilkan(10, 31);
tampilkan(11, 4);
tampilkan(12, 4);
tampilkan(13, 4);
tampilkan(14, 4);
tampilkan(15, 4);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//NATA
tampilkan(0, 17);
tampilkan(1, 19);
tampilkan(2, 21);
tampilkan(3, 25);
tampilkan(4, 17);
tampilkan(5, 960);
tampilkan(6, 576);
tampilkan(7, 960);
tampilkan(8, 576);
tampilkan(9, 576);
tampilkan(10, 31);
tampilkan(11, 4);
tampilkan(12, 4);
tampilkan(13, 4);
tampilkan(14, 4);
tampilkan(15, 4);
tampilkan(16, 960);
tampilkan(17, 576);
tampilkan(18, 960);
tampilkan(19, 576);
tampilkan(20, 576);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//NATAL
tampilkan(0, 17);
tampilkan(1, 19);
tampilkan(2, 21);
tampilkan(3, 25);
tampilkan(4, 17);
tampilkan(5, 960);
tampilkan(6, 576);
tampilkan(7, 960);
tampilkan(8, 576);
tampilkan(9, 576);
tampilkan(10, 31);
tampilkan(11, 4);
tampilkan(12, 4);
tampilkan(13, 4);
tampilkan(14, 4);
tampilkan(15, 4);
tampilkan(16, 960);
tampilkan(17, 576);
tampilkan(18, 960);
tampilkan(19, 576);
tampilkan(20, 576);
tampilkan(21, 2);
tampilkan(22, 2);
tampilkan(23, 2);
tampilkan(24, 2);
tampilkan(25, 2);
tampilkan(26, 30);
tampilkan(27, 0);
delay(1000);


//A
tampilkan(0, 15);
tampilkan(1, 9);
tampilkan(2, 15);
tampilkan(3, 9);
tampilkan(4, 9);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//AM
tampilkan(5, 0);
tampilkan(6, 17);
tampilkan(7, 27);
tampilkan(8, 21);
tampilkan(9, 17);
tampilkan(10, 17);
delay(1000);

//AMA
tampilkan(11, 0);
tampilkan(12, 15);
tampilkan(13, 9);
tampilkan(14, 15);
tampilkan(15, 9);
tampilkan(16, 9);
delay(1000);

//AMA I
tampilkan(11, 448);
tampilkan(12, 143);
tampilkan(13, 137);
tampilkan(14, 143);
tampilkan(15, 457);
tampilkan(16, 9);
delay(1000);

//AMA IN
tampilkan(17, 544);
tampilkan(18, 608);
tampilkan(19, 672);
tampilkan(20, 800);
tampilkan(21, 544);
delay(1000);

//AMA INA
tampilkan(22, 0);
tampilkan(23, 960);
tampilkan(24, 576);
tampilkan(25, 960);
tampilkan(26, 576);
tampilkan(27, 576);
delay(1000);

  //H
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 390);
  tampilkan(5, 390);
  tampilkan(6, 390);
  tampilkan(7, 510);
  tampilkan(8, 510);
  tampilkan(9, 390);
  tampilkan(10, 390);
  tampilkan(11, 390);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //K
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 0);
  tampilkan(5, 0);
  tampilkan(6, 0);
  tampilkan(7, 0);
  tampilkan(8, 390);
  tampilkan(9, 198);
  tampilkan(10, 102);
  tampilkan(11, 30);
  tampilkan(12, 30);
  tampilkan(13, 102);
  tampilkan(14, 198);
  tampilkan(15, 390);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //B
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 0);
  tampilkan(5, 0);
  tampilkan(6, 0);
  tampilkan(7, 0);
  tampilkan(8, 0);
  tampilkan(9, 0);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 254);
  tampilkan(13, 262);
  tampilkan(14, 262);
  tampilkan(15, 254);
  tampilkan(16, 254);
  tampilkan(17, 262);
  tampilkan(18, 262);
  tampilkan(19, 254);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //P
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 0);
  tampilkan(5, 0);
  tampilkan(6, 0);
  tampilkan(7, 0);
  tampilkan(8, 0);
  tampilkan(9, 0);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 254);
  tampilkan(17, 390);
  tampilkan(18, 390);
  tampilkan(19, 254);
  tampilkan(20, 6);
  tampilkan(21, 6);
  tampilkan(22, 6);
  tampilkan(23, 6);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //Pondok kelapa
  tampilkan(0, 7);
  tampilkan(1, 5);
  tampilkan(2, 7);
  tampilkan(3, 1);
  tampilkan(4, 1);
  tampilkan(5, 0);
  tampilkan(6, 0);
  tampilkan(7, 0);
  tampilkan(8, 0);
  tampilkan(9, 0);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //pOndok kelapa
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 14);
  tampilkan(3, 10);
  tampilkan(4, 10);
  tampilkan(5, 14);
  tampilkan(6, 0);
  tampilkan(7, 0);
  tampilkan(8, 0);
  tampilkan(9, 0);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //poNdok kelapa
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 36);
  tampilkan(5, 44);
  tampilkan(6, 52);
  tampilkan(7, 36);
  tampilkan(8, 0);
  tampilkan(9, 0);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //ponDok kelapa
  tampilkan(0, 0);
  tampilkan(1, 0);
  tampilkan(2, 0);
  tampilkan(3, 0);
  tampilkan(4, 0);
  tampilkan(5, 0);
  tampilkan(6, 24);
  tampilkan(7, 40);
  tampilkan(8, 40);
  tampilkan(9, 24);
  tampilkan(10, 0);
  tampilkan(11, 0);
  tampilkan(12, 0);
  tampilkan(13, 0);
  tampilkan(14, 0);
  tampilkan(15, 0);
  tampilkan(16, 0);
  tampilkan(17, 0);
  tampilkan(18, 0);
  tampilkan(19, 0);
  tampilkan(20, 0);
  tampilkan(21, 0);
  tampilkan(22, 0);
  tampilkan(23, 0);
  tampilkan(24, 0);
  tampilkan(25, 0);
  tampilkan(26, 0);
  tampilkan(27, 0);
  delay(1000);
  
  //pondOk kelapa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 112);
tampilkan(9, 80);
tampilkan(10, 80);
tampilkan(11, 112);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondoK kelapa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 288);
tampilkan(11, 160);
tampilkan(12, 96);
tampilkan(13, 160);
tampilkan(14, 288);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok Kelapa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 9);
tampilkan(8, 5);
tampilkan(9, 3);
tampilkan(10, 5);
tampilkan(11, 9);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok kElapa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 14);
tampilkan(10, 2);
tampilkan(11, 14);
tampilkan(12, 2);
tampilkan(13, 14);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok keLapa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 4);
tampilkan(12, 4);
tampilkan(13, 4);
tampilkan(14, 4);
tampilkan(15, 28);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok kelApa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 56);
tampilkan(14, 40);
tampilkan(15, 56);
tampilkan(16, 40);
tampilkan(17, 40);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok kelaPa
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 112);
tampilkan(16, 80);
tampilkan(17, 112);
tampilkan(18, 16);
tampilkan(19, 16);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//pondok kelapA
tampilkan(0, 0);
tampilkan(1, 0);
tampilkan(2, 0);
tampilkan(3, 0);
tampilkan(4, 0);
tampilkan(5, 0);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 448);
tampilkan(18, 320);
tampilkan(19, 448);
tampilkan(20, 320);
tampilkan(21, 320);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//2
tampilkan(0, 248);
tampilkan(1, 200);
tampilkan(2, 96);
tampilkan(3, 48);
tampilkan(4, 24);
tampilkan(5, 248);
tampilkan(6, 0);
tampilkan(7, 0);
tampilkan(8, 0);
tampilkan(9, 0);
tampilkan(10, 0);
tampilkan(11, 0);
tampilkan(12, 0);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//20
tampilkan(0, 248);
tampilkan(1, 200);
tampilkan(2, 96);
tampilkan(3, 48);
tampilkan(4, 24);
tampilkan(5, 248);
tampilkan(6, 0);
tampilkan(7, 248);
tampilkan(8, 136);
tampilkan(9, 136);
tampilkan(10, 136);
tampilkan(11, 136);
tampilkan(12, 248);
tampilkan(13, 0);
tampilkan(14, 0);
tampilkan(15, 0);
tampilkan(16, 0);
tampilkan(17, 0);
tampilkan(18, 0);
tampilkan(19, 0);
tampilkan(20, 0);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//201
tampilkan(0, 248);
tampilkan(1, 200);
tampilkan(2, 96);
tampilkan(3, 48);
tampilkan(4, 24);
tampilkan(5, 248);
tampilkan(6, 0);
tampilkan(7, 248);
tampilkan(8, 136);
tampilkan(9, 136);
tampilkan(10, 136);
tampilkan(11, 136);
tampilkan(12, 248);
tampilkan(13, 0);
tampilkan(14, 32);
tampilkan(15, 48);
tampilkan(16, 32);
tampilkan(17, 32);
tampilkan(18, 32);
tampilkan(19, 32);
tampilkan(20, 112);
tampilkan(21, 0);
tampilkan(22, 0);
tampilkan(23, 0);
tampilkan(24, 0);
tampilkan(25, 0);
tampilkan(26, 0);
tampilkan(27, 0);
delay(1000);

//2015
tampilkan(0, 248);
tampilkan(1, 200);
tampilkan(2, 96);
tampilkan(3, 48);
tampilkan(4, 24);
tampilkan(5, 248);
tampilkan(6, 0);
tampilkan(7, 248);
tampilkan(8, 136);
tampilkan(9, 136);
tampilkan(10, 136);
tampilkan(11, 136);
tampilkan(12, 248);
tampilkan(13, 0);
tampilkan(14, 32);
tampilkan(15, 48);
tampilkan(16, 32);
tampilkan(17, 32);
tampilkan(18, 32);
tampilkan(19, 32);
tampilkan(20, 112);
tampilkan(21, 0);
tampilkan(22, 248);
tampilkan(23, 8);
tampilkan(24, 248);
tampilkan(25, 128);
tampilkan(26, 128);
tampilkan(27, 248);
delay(1000);
}

void on(int baris,int kolom)
{
  kordinat1[baris][kolom]=1;
}

void off(int baris,int kolom)
{
  kordinat1[baris][kolom]=0;
}
