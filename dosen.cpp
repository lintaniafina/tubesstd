#include "dosen.h"
#include <iostream>

using namespace std;
void createListdosen(List_dosen &L){
    first(L)=nil;
}
adr_dosen alokasidosen(infotypedosen dosen){
    adr_dosen P=new elmlist_dosen;
    info(P).nama=dosen.nama;
    info(P).no_telp=dosen.no_telp;
    next(P)=nil;
}
void dealokasidosen(adr_dosen &P){
    delete P;
}

void printdosen(List_dosen L){
    if(first(L)!=nil){
        adr_dosen P=first(L);
        int J=1;
        while(P!=nil){
            cout<<"Dosen"<<J<<endl;
            cout<<"Nama Dosen:"<<info(P).nama<<" "<<endl;
            cout<<"No Telp Dosen:"<<info(P).no_telp<<" "<<endl;
            P=next(P);
            J++;
            cout<<endl;
        }
    }else{
        cout<<"Tidak ada data dosen yang dapat dilihat"<<endl;
    }
}

adr_dosen finddosen(List_dosen L, infotypedosen P){
    if(first(L) != nil && P.nama != "" && P.no_telp != ""){
        adr_dosen q = first(L);
        while(next(q) != nil &&  info(q).nama != P.nama && info(q).no_telp != P.no_telp){
            q = next(q);
        }
        if(info(q).nama == P.nama && info(q).no_telp == P.no_telp){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
adr_dosen searchdosen(List_dosen L, infotypedosen P){
    if(first(L) != nil && P.nama != "" /*&& P.no_telp != ""*/){
        adr_dosen q = first(L);
        while(next(q) != nil &&  info(q).nama != P.nama /*&& info(q).no_telp != P.no_telp*/){
            q = next(q);
        }
        if(info(q).nama == P.nama /*&& info(q).no_telp == P.no_telp*/){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
void insertDosen(List_dosen &L, adr_dosen P){
    if(first(L) != nil){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
    }
}
void insertFirstdosen(List_dosen &L, adr_dosen P){
    if(first(L)!=nil){
        next(P)=first(L);
        first(L)=P;
    }else{
        first(L)=P;
    }
}
void insertAfterdosen(List_dosen &L, adr_dosen Prec, adr_dosen P){
    if(first(L)!=nil && Prec!=nil){
        adr_dosen q=first(L);
        while(next(q)!=nil && info(q).nama!=info(Prec).nama&&info(q).no_telp!=info(Prec).no_telp){
            q=next(q);
        }
        if(info(q).nama==info(Prec).nama && info(q).no_telp==info(Prec).no_telp){
            if(next(q)==nil){
                insertLastdosen(L,P);
            }else{
                next(P)=next(q);
                next(q)=P;
            }
        }else{
            cout<<"Data dosen tidak ditemukan"<<endl;
        }
    }else{
        cout<<"List dosen kosong"<<endl;
    }
}
void insertLastdosen(List_dosen &L, adr_dosen P){
    if(first(L)!=nil){
        adr_dosen Q=first(L);
        while(next(Q)!=nil){
            Q=next(Q);
        }
        next(Q)=P;
        next(P)=nil;
    }else{
        insertFirstdosen(L,P);
    }
}
void deleteFirstdosen(List_dosen &L){
    if(first(L)!=nil){
        adr_dosen P=first(L);
        first(L)=next(P);
        next(P)=nil;
        dealokasidosen(P);
    }else{
        cout<<"Tidak ada data dosen"<<endl;
    }
}
void deleteLastdosen(List_dosen &L){
    if(first(L)!=nil){
        adr_dosen q=first(L);
        while(next(next(q))!=nil){
            q=next(q);
        }
        adr_dosen P=next(q);
        next(P)=nil;
        next(q)=nil;

        dealokasidosen(P);
    }else{
        cout<<"List dosen kosong"<<endl;
    }
}
void deleteAfterdosen(List_dosen &L, adr_dosen Prec){
    if(first(L)!=nil){
        adr_dosen q=first(L);
        while(next(q)!=nil && info(q).nama!=info(Prec).nama&&info(q).no_telp!=info(Prec).no_telp){
            q=next(q);
        }
        if(info(q).nama==info(Prec).nama && info(q).no_telp==info(Prec).no_telp){
            if(next(q)==nil){
                cout<<"Tidak berhasil menghapus data dosen"<<endl;
            }else if(next(next(q))==nil){
                deleteLastdosen(L);
            }else{
                adr_dosen P=next(q);
                next(q)=next(P);
                next(P)=nil;
                dealokasidosen(P);
            }
        }else{
            cout<<"Tidak ditemukan data dosen"<<endl;
        }
    }else{
        cout<<"List dose kosong"<<endl;

    }
}
void deleteDosen(List_dosen &L, infotypedosen D){
    if(first(L) != nil && D.nama != "" && D.no_telp != ""){
        adr_dosen P = finddosen(L, D);
        if(P != nil){
            if(P == first(L)){
                deleteFirstdosen(L);
            }else if(next(P) == nil){
                deleteLastdosen(L);
            }else{
                adr_dosen Q = first(L);
                while(next(Q) != P){
                    Q = next(Q);
                }
                deleteAfterdosen(L,Q);
            }
        }else{
            cout << "Tidak dapat menghapus data dosen,data tidak ada dalam List" << endl;
        }
    }else{
        cout << "Tidak dapat menghapus list,karena list sudah kosong" << endl;
    }
}


