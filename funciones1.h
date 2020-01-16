//---------------------------------------------------------------------------

#ifndef funcionesH
#define funcionesH
//---------------------------------------------------------------------------
#endif
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define MAX(A,B) ((A) > (B) ? (A) : (B))

void FuncionRecorta( Graphics::TBitmap * , int x1, int y1, int x2, int y2,Graphics::TBitmap *, TImage * );
void FuncionBrilloContraste(TImage *image, Byte **auximage, float a,  int b);
void escalaGris(TImage *image);
void detector(TImage *image);
void metal(TImage *image);
void convolucion3x3( Graphics::TBitmap *, int k );
void imagenAmatriz(TImage *image);
int **Convolution(int *a, int nlin, int ncol, int nk, int **r, int **k);
int **ConvolutionHV(int *a, int nlin, int ncol, int nk, int **r, int **k, int **k1);
int *Histograma(int **,int *,  int ncol, int nlin);
int **EcualizaHistograma(int Nlin, int Ncol, int Nhi, int Nhf, int **M, int **R);
int **Negativo (int **a, int nlin, int ncol , int **r);



