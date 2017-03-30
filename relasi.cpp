#include "matakuliah.h"
#include "dosen.h"
#include "relasi.h"

void createListrelasi(List_r &L){
    first(L)=nil;
    last(L)=nil;
}
adr_relasi alokasirelasi(infotype_r relasi){
    adr_relasi P=new elmlist_r;
    info(P)=relasi;
    next(P)=nil;
    prev(P)=nil;
}
void dealokasirelasi(adr_relasi &P){
    delete P;
}
void insertRelasi(List_r &L, adr_relasi P){
    if(first(L) != nil && last(L) != nil){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void insertFirstrelasi(List_r &L, adr_relasi P){
    if(first(L)!=nil && last(L)!=nil){
        next(P)=first(L);
        prev(first(L))=P;
    }else{
        first(L)=P;
        last(L)=P;
    }
}
void insertAfterrelasi(List_r &L, adr_relasi Prec, adr_relasi P){
    if(first(L)!=nil && last(L)!=nil && Prec!=nil){
        adr_relasi q=first(L);
        while(next(q)!=nil && addressDosen(q)!= addressDosen(Prec) && addressMatkul(q)!=addressMatkul(Prec)){
            q=next(q);
        }
        if(addressDosen(q)== addressDosen(Prec) && addressMatkul(q)==addressMatkul(Prec)){
            if(next(q)==nil){
                insertLastrelasi(L,P);
            }else{
                next(P)=next(q);
                prev(next(q))=P;
                next(q)=P;
                prev(P)=q;
            }
        }else{
            cout<<"Tidak ditemukan relasi"<<endl;
        }
    }else{
        cout<<"Tidak ada relasi"<<endl;
    }
}
void insertLastrelasi(List_r &L, adr_relasi P){
    if(first(L)!=nil && last(L)!=nil){
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }else{
        insertFirstrelasi(L,P);
    }
}

void deleteFirstrelasi(List_r &L){
    if(first(L)!=nil && last(L)!=nil){
        adr_relasi P=first(L);
        first(L)=next(P);
        next(P)=nil;
    }else{
        cout<<"Tidak ada relasi"<<endl;
    }
}
void deleteLastrelasi(List_r &L){
    if(first(L)!=nil && last(L)!=nil){
        adr_relasi q=last(L);
        last(L)=prev(q);
        next(last(L))=nil;
        delete q;
    }else{
        cout<<"Tidak ada relasi"<<endl;
    }
}
void deleteAfterrelasi(List_r &L, adr_relasi Prec){
if(first(L)!=nil && last(L)!=nil && Prec!=nil){
        adr_relasi q=first(L);
        while(next(q)!=nil && addressDosen(q)!= addressDosen(Prec) && addressMatkul(q)!=addressMatkul(Prec)){
            q=next(q);
        }
        if(addressDosen(q)== addressDosen(Prec) && addressMatkul(q)==addressMatkul(Prec)){
            if(next(q)==nil){
                deleteLastrelasi(L);
            }else{
                adr_relasi r=next(q);
                next(q)=next(r);
                prev(next(r))=q;
                delete r;
            }
        }else{
            cout<<"Tidak ditemukan relasi"<<endl;
        }
    }else{
        cout<<"Tidak ada relasi"<<endl;
    }
}
void deleteRelasi(List_r &L, infotype_r R){
    if(first(L) != nil && last(L)!= nil && R.addressMatkul != nil && R.addressDosen != nil){
        adr_relasi P = findrelasi(L,R);
        if(P != nil){
            if(P == first(L)){
                deleteFirstrelasi(L);
            }else if(P == last(L)){
                deleteLastrelasi(L);
            }else{
                adr_relasi prec = prev(P);
                deleteAfterrelasi(L,prec);
            }
        }else{
            cout << "Tidak dapat menghapus list,data tidak ada dalam List" << endl;
        }
    }else{
        cout << "Tidak dapat menghapus list,data mata kuliah kosong" << endl;
    }
}
void printrelasi(List_r L){
    if(first(L)!=nil){
        adr_relasi P=first(L);
        int J=1;
        while(P!=nil){
            cout<<""<<J<<endl;
            cout<<"Dosen:"<<info(addressDosen(P)).nama<<" "<<endl;
            cout<<"Matkul:"<<info(addressMatkul(P)).nama_matkul<<" "<<endl;
            P=next(P);
            J++;
            cout<<endl;
        }
    }else{
        cout<<"Tidak ada relasi yang dapat dilihat"<<endl;
    }
}
adr_relasi findrelasi(List_r L, infotype_r P){
if(first(L) != nil && last(L)!=nil && P.addressDosen != nil && P.addressMatkul != nil){
        adr_relasi relasi=nil;
        adr_relasi q = first(L);
        while(q!=nil){
        if(addressDosen(q)==P.addressDosen&& addressMatkul(q)==P.addressMatkul){
            relasi=q;
        }
            q=next(q);
        }
        if(relasi!=nil){
            return relasi;
        }else{
            return nil;
        }
}else{
    return nil;
}

}
