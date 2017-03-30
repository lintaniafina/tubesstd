#include "matakuliah.h"
#include <iostream>

using namespace std;
void createListmatkul(List_matkul &L){
    first(L)=nil;
}
adr_matkul alokasimatkul(infotypematkul matkul){
    adr_matkul P=new elmlist_matkul;
    info(P).nama_matkul=matkul.nama_matkul;
    info(P).deskripsi=matkul.deskripsi;
    next(P)=nil;
}
void dealokasimatkul(adr_matkul &P){
     delete P;
}
void insertMatkul(List_matkul &L, adr_matkul P){
    if(first(L) != nil){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
    }
}
void insertFirstmatkul(List_matkul &L, adr_matkul P){
    if(first(L)!=nil){
        next(P)=first(L);
        first(L)=P;
    }else{
        first(L)=P;
    }
}
void insertAftermatkul(List_matkul &L, adr_matkul Prec, adr_matkul P){
     if(first(L)!=nil && Prec!=nil){
        adr_matkul q=first(L);
        while(next(q)!=nil && info(q).nama_matkul!=info(Prec).nama_matkul && info(q).deskripsi!=info(Prec).deskripsi){
            q=next(q);
        }
        if(info(q).nama_matkul==info(Prec).nama_matkul && info(q).deskripsi==info(Prec).deskripsi){
            if(next(q)==nil){
                insertLastmatkul(L,P);
            }else{
                next(P)=next(q);
                next(q)=P;
            }
        }else{
            cout<<"Data mata kuliah tidak ditemukan"<<endl;
        }
    }else{
        cout<<"List mata kuliah kosong"<<endl;
    }
}
void insertLastmatkul(List_matkul &L, adr_matkul P){
    if(first(L)!=nil){
        adr_matkul Q=first(L);
        while(next(Q)!=nil){
            Q=next(Q);
        }
        next(Q)=P;
        next(P)=nil;
    }else{
        insertFirstmatkul(L,P);
    }
}
void deleteFirstmatkul(List_matkul &L){
    if(first(L)!=nil){
        adr_matkul P=first(L);
        first(L)=next(P);
        next(P)=nil;
        dealokasimatkul(P);
    }else{
        cout<<"Tidak ada data mata kuliah"<<endl;
    }
}
void deleteLastmatkul(List_matkul &L){
    if(first(L)!=nil){
        adr_matkul q=first(L);
        while(next(next(q))!=nil){
            q=next(q);
        }
        adr_matkul P=next(q);
        next(P)=nil;
        next(q)=nil;
        dealokasimatkul(P);
    }else{
        cout<<"List mata kuliah kosong"<<endl;
    }
}
void deleteAftermatkul(List_matkul &L, adr_matkul Prec){
    if(first(L)!=nil && Prec != nil){
        adr_matkul q=first(L);
        while(next(q)!=nil && info(q).nama_matkul!=info(Prec).nama_matkul && info(q).deskripsi!=info(Prec).deskripsi){
            q=next(q);
        }
        if(info(q).nama_matkul==info(Prec).nama_matkul && info(q).deskripsi==info(Prec).deskripsi){
            if(next(q)==nil){
                cout<<"Tidak berhasil menghapus data dosen"<<endl;
            }else if(next(next(q))==nil){
                deleteLastmatkul(L);
            }else{
                adr_matkul P=next(q);
                next(q)=next(P);
                next(P)=nil;
                dealokasimatkul(P);
            }
        }else{
            cout<<"Tidak ditemukan data mata kuliah"<<endl;
        }
    }else{
        cout<<"List mata kuliah kosong"<<endl;
    }
}
void deleteMatkul(List_matkul &L, infotypematkul M){
    if(first(L) != nil && M.nama_matkul!= "" && M.deskripsi != ""){
        adr_matkul P = findmatkul(L, M);
        if(P != nil){
            if(P == first(L)){
                deleteFirstmatkul(L);
            }else if(next(P) == nil){
                deleteLastmatkul(L);
            }else{
                adr_matkul Q = first(L);
                while(next(Q) != P){
                    Q = next(Q);
                }
                deleteAftermatkul(L,Q);
            }
        }else{
            cout << "Tidak dapat menghapus data mata kuliah,data tidak ada dalam List" << endl;
        }
    }else{
        cout << "Tidak dapat menghapus list,karena list sudah kosong" << endl;
    }
}
void printmatkul(List_matkul L){
    if(first(L)!=nil){
        adr_matkul P=first(L);
        int J=1;
        while(P!=nil){
            cout<<"Mata Kuliah"<<J<<endl;
            cout<<"Nama Matkul:"<<info(P).nama_matkul<<" "<<endl;
            cout<<"Deskripsi:"<<info(P).deskripsi<<" "<<endl;
            P=next(P);
            J++;
            cout<<endl;
        }
    }else{
        cout<<"Tidak ada data mata kuliah yang dapat dilihat"<<endl;
    }
}
adr_matkul findmatkul(List_matkul L, infotypematkul P){
    if(first(L) != nil && P.nama_matkul != "" && P.deskripsi != ""){
        adr_matkul q = first(L);
        while(next(q) != nil &&  info(q).nama_matkul != P.nama_matkul && info(q).deskripsi != P.deskripsi){
            q = next(q);
        }
        if(info(q).nama_matkul == P.nama_matkul && info(q).deskripsi== P.deskripsi){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
