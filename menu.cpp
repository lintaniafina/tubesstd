#include "dosen.h"
#include "matakuliah.h"
#include "relasi.h"
#include "menu.h"
void clearscreen(){
    system ("CLS");
}
int inputmenu(){
    int j=0;
    bool stop=false;
    clearscreen();
    cout << "Menu" << endl;
    cout << "1. Print" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Find" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih menu : " ;
    do{
        //cout<<"Pilih Menu"<<endl;
        cin>>j;
        if(j>=0 && j<=4){
            stop=true;
        }else{
            cout<<"Coba Ulangi"<<endl;
        }
    }while(stop!=true);
    return j;
}
int inputsubmenu(){
    int j;
    bool stop=false;
    clearscreen();
    cout << "List" << endl;
    cout << "1. Dosen" << endl;
    cout << "2. Matkul" << endl;
    cout << "3. Relasi" << endl;
    cout << "Pilih List : " ;
    do{
        //cout<<"Pilih List"<<endl;

        cin>>j;
        if(j>=0 && j<=3){
            stop=true;
        }else{
            cout<<"Coba Ulangi"<<endl;
        }
    }while(stop!=true);
    return j;
}
void menu(int inputmenu, int sub, List_dosen &LD, List_matkul &LM, List_r &LR){
    switch (inputmenu) {
    case 1:
        switch (sub){
        case 1:
            clearscreen();
            cout << "Print List Dosen" << endl;
            printdosen(LD);
            getch();
        break;
        case 2:
            clearscreen();
            cout << "Print List Mata Kuliah" << endl;
            printmat(LR,LM);
            getch();
        break;
        case 3:
            clearscreen();
            cout << "Print List Relasi" << endl;
            printRel(LD,LM,LR);
            getch();
        break;
        }
    break;
    case 2:

        switch (sub) {
        case 1:
            inputdosen(LD);
            getch();
        break;
        case 2:
            inputmatkul(LM,LR,LD);
            getch();
        break;
        case 3:
            inputrelasi(LR,LD,LM);
            getch();
        break;
        }
    break;
    case 3:

        switch (sub){
        case 1:
            deletedosen(LD,LR);
        break;
        case 2:
            deletematkul(LM,LR);
        break;
        case 3:
            deleterelasi(LR,LD,LM);
        break;
        }

    break;
    case 4:
        switch (sub){
        case 1:
            findDosen(LD);
            getch();
        break;
        case 2:
            findMatkul(LM);
            getch();
        break;
        case 3:
            findRelasi(LR,LD,LM);
            getch();
        break;
        }
    break;
}
}
void tampilmenu(){
    List_dosen D;
    List_matkul M;
    List_r R;
    createListdosen(D);
    createListmatkul(M);
    createListrelasi(R);
    int X,Y;
    bool stop = false;
    do{
        X = inputmenu();
        if(X != 0){
            Y = inputsubmenu();
            if(Y != 0){
                menu(X,Y,D,M,R);
            }
        }else{
            stop = true;
        }
    }while(stop != true);
}
void inputdosen(List_dosen &L){
    infotypedosen P;
    clearscreen();
    cout<<"Input Dosen"<<endl;
    cout<<"Nama dosen : ";
    cin>>P.nama;
    cout<<"No telp dosen : ";
    cin>>P.no_telp;
    adr_dosen D = finddosen(L, P);
    if(D!= nil){
        cout << endl << "Tidak dapat menambahkan data kedalam list dosen, karena data sudah ada" << endl;
        getch();
    }else{
    insertFirstdosen(L,alokasidosen(P));
    cout<<"Data dosen telah ditambahakan dalam list dosen"<<endl;
    }
}
void inputmatkul(List_matkul &LM,List_r &LR,List_dosen LD){
    infotypematkul P;
    clearscreen();
    bool stop = false;
    bool yesno = false;
    string X;
    cout << "Masukkan data matkul" << endl;
    cout << "Nama matkul : ";
    cin >> P.nama_matkul;
    cout << "Deskripsi : ";
    cin >> P.deskripsi;
    adr_matkul M = findmatkul(LM, P);
    if(M != nil){
        cout << endl << "Tidak dapat menambahkan data kedalam list matkul, karena data sudah ada" << endl;
        getch();
    }else{
        insertFirstmatkul(LM,alokasimatkul(P));
        do{
            clearscreen();
            cout << "Membuat relasi antara dosen dengan mata kuliah setelah berhasil di insert" << endl;
            infotypedosen D;
            cout << "Nama dosen yang mengajar " << P.nama_matkul << " : ";
            cin >> D.nama;
            cout << "No telp dosen yang mengajar " << P.nama_matkul << " : ";
            cin >> D.no_telp;
            adr_dosen AD = finddosen(LD,D);
            adr_matkul MK = findmatkul(LM, P);
            if(AD != nil && MK != nil){
                infotype_r R;
                R.addressDosen = AD;
                R.addressMatkul = MK;
                adr_relasi Relasi = findrelasi(LR, R);
                if(Relasi != nil){
                    cout << endl << "Tidak dapat menambahkan relasi, relasi sudah ada" << endl;
                    getch();
                }else{
                    int j = Hitungmatkuldaridosen(LR, D);
                    if(j < 3){
                        insertRelasi(LR, alokasirelasi(R));
                        stop = true;
                        cout << endl << "Berhasil menambahkan data matkul dalam list matkul dan juga membuat relasinya" << endl << endl;
                        getch();
                    }else{
                        cout << endl << "Tidak dapat menambahkan relasi, karna sudah penuh" << endl;
                        do{
                            cout << "Input lagi ? Yes/No : ";
                            cin >> X;
                            if(X == "yes" || X == "YES"||X == "Yes"){
                                yesno = true;
                            }else if(X == "no" || X == "NO"||X=="No"){
                                yesno = true;
                                stop = true;
                                deleteMatkul(LM, P);
                            }else{
                                cout << "Coba lagi" << endl;
                                yesno = false;
                            }
                        }while(yesno != true);
                    }
                }
            }else{
                cout << endl << "Tidak bisa menambahkan relasi, dosen sudah ada dalam list" << endl;
                do{
                    cout << "Input lagi ? (Yes/No) : ";
                    cin >> X;
                    if(X == "yes" || X == "YES"||X == "Yes"){
                        yesno = true;
                    }else if(X == "no" || X == "NO"||X=="No"){
                        yesno = true;
                        stop = true;
                        deleteMatkul(LM, P);
                    }else{
                        cout << "Masukkan Yes/No" << endl;
                        yesno = false;
                    }
                }while(yesno != true);
            }
        }while(stop != true);
}
}
void inputrelasi(List_r &LR,List_dosen LD,List_matkul LM){
    clearscreen();
    cout << "Membuat relasi antara dosen dengan matkul" << endl;
    infotypedosen D;
    cout << "Nama dosen : ";
    cin >> D.nama;
    cout << "Nomor telp: ";
    cin >> D.no_telp;
    adr_dosen AD= finddosen(LD,D);
    infotypematkul M;
    cout << "Nama mata kuliah: ";
    cin >> M.nama_matkul;
    cout << "Deskripsi : ";
    cin >> M.deskripsi;
    adr_matkul MK = findmatkul(LM, M);
    if(AD != nil && MK != nil){
        infotype_r R;
        R.addressDosen = AD;
        R.addressMatkul = MK;
        adr_relasi rel = findrelasi(LR, R);
        if(rel != nil){
            cout << endl << "Tidak dapat menambahkan relasi,karena relasi sudah ada" << endl;
        }else{
            int j = Hitungmatkuldaridosen(LR, D);
            if(j < 3){
                insertRelasi(LR, alokasirelasi(R));
                cout << endl << "Berhasil menambahkan relasi" << endl;
            }else{
                cout << endl << "Tidak dapat menambahkan relasi, karna sudah penuh" << endl;
            }
        }
    }else{
        cout << endl << "Tidak dapat menambahkan relasi" << endl;
}
    }

void deletedosen(List_dosen &D,List_r &R){
    clearscreen();
    infotypedosen P;
    infotype_r Q;
    cout<<"Delete Dosen"<<endl;
    cout<<"Nama dosen : ";
    cin>>P.nama;
    cout<<"No telp dosen : ";
    cin>>P.no_telp;
    adr_relasi S=first(R);
     while(S != nil){
        if(info(addressDosen(S)).nama == P.nama && info(addressDosen(S)).no_telp == P.no_telp){
            Q.addressDosen = addressDosen(S);
            Q.addressMatkul = addressMatkul(S);
            deleteRelasi(R,Q);
        }
        S = next(S);
    }
    deleteDosen(D,P);
    cout<<endl<<"Data "<<P.nama<<" "<<"telah dihapus dari list dosen"<<endl;
    getch();
}
void deletematkul(List_matkul &M,List_r &R){
    clearscreen();
    infotypematkul P;
    infotype_r Q;
    cout<<"Delete Mata Kuliah"<<endl;
    cout<<"Nama mata kuliah : ";
    cin>>P.nama_matkul;
    cout<<"Deskripsi : ";
    cin>>P.deskripsi;
    adr_relasi S=first(R);
     while(S != nil){
        if(info(addressMatkul(S)).nama_matkul== P.nama_matkul && info(addressMatkul(S)).deskripsi == P.deskripsi){
            Q.addressDosen = addressDosen(S);
            Q.addressMatkul = addressMatkul(S);
            deleteRelasi(R, Q);
        }
        S = next(S);
    }
    deleteMatkul(M,P);
    cout<<endl<<"Data"<<" "<<P.nama_matkul<<" "<<"telah dihapus dari list matkul"<<endl;
    getch();
}
void deleterelasi(List_r &LR,List_dosen LD,List_matkul LM){
    clearscreen();
    cout << "Menghapus relasi antara dosen dan matkul" << endl;
    infotypedosen D;
    cout << "Masukkan nama dosen yang akan dihapus relasinya : ";
    cin >> D.nama;
    cout << "Masukkan nomor telepon dosen yang akan dihapus relasinya : ";
    cin >> D.no_telp;
    adr_dosen P = finddosen(LD,D);
    infotypematkul M;
    cout << "Masukkan nama mata kuliah yang akan dihapus relasinya : ";
    cin >> M.nama_matkul;
    cout << "Masukkan deskripsi yang akan dihapus relasinya : ";
    cin >> M.deskripsi;
    adr_matkul Q = findmatkul(LM, M);
    if(P != nil && Q != nil){
        int j = Hitungdosendarimatkul(LR, M);
        if(j == 1){
            cout << "Tidak dapat menghapus relasi mata kuliah " << M.nama_matkul << " karna satu mata kuliah diajar oleh minimal 1 dosen" << endl;
        }else{
            infotype_r  r;
            r.addressDosen= P;
            r.addressMatkul= Q;
            deleteRelasi(LR,r);
            cout << endl << "Berhasil menghapus relasi" << endl;
        }
        }else{
        cout << endl << "Tidak dapat menghapus relasi" << endl;
    }
    getch();
}
void findDosen(List_dosen &L){
    infotypedosen P;
    clearscreen();
    cout << "Mencari data dosen" << endl;
    cout << "Masukkan nama dosen yang akan dicari : ";
    cin >> P.nama;
    //cout << "Masukkan nomor telepon dosen yang akan dicari : ";
    //cin >> P.no_telp;
    adr_dosen Q = searchdosen(L, P);
    if(Q != nil){
        cout << "Dosen " << Q->info.nama << " ada di dalam list, dengan data" << endl;
        cout << "Nama         : "<<Q->info.nama<<endl;
        cout << "Nomor telepon: "<<Q->info.no_telp<<endl;
    }else{
        cout << "Dosen " << P.nama << " tidak ada di dalam list" << endl;
    }
}
void findMatkul(List_matkul &L){
    infotypematkul P;
    clearscreen();
    cout << "Mencari data matkul" << endl;
    cout << "Masukkan nama matkul yang akan dicari : ";
    cin >> P.nama_matkul;
    adr_matkul Q = findmatkul(L, P);
    if(Q != nil){
        cout << "Matakuliah " << Q->info.nama_matkul << " ada di dalam list, dengan data" << endl;
        cout << "Matakuliah: "<< Q->info.nama_matkul<<endl;
        cout << "Deskripsi : "<< Q->info.deskripsi<<endl;
    }else{
        cout << "Matakuliah " << P.nama_matkul<< " tidak ada di dalam list" << endl;
    }
}
void findRelasi(List_r &R,List_dosen D,List_matkul M){
    clearscreen();
    cout << "Mencari data dalam relasi" << endl;
    infotypedosen i;
    cout << "Masukkan nama dosen : ";
    cin >> i.nama;
    adr_dosen P = searchdosen(D,i);
    infotypematkul s;
    cout << "Masukkan nama matkul : ";
    cin >> s.nama_matkul;
    adr_matkul Q = findmatkul(M, s);
    //cout<<Q->info.nama_matkul;
    if(P != nil && Q != nil){
        infotype_r r;
        r.addressDosen = P;
        r.addressMatkul =Q;
        adr_relasi relasi = findrelasi(R, r);
        if(relasi != nil){
            cout << "Relasi antara dosen " << P->info.nama << " dan matkul " << Q->info.nama_matkul << " ada di dalam list" << endl;
            cout << "Dosen "<<P->info.nama<<" mempunyai nomor telepon "<<P->info.no_telp<<" dan mengampu matakuliah "<<Q->info.nama_matkul<<endl;
            cout << "Yaitu matakuliah dengan deskripsi: "<<Q->info.deskripsi<<endl;
        }else{
            cout << "Relasi antara dosen " << i.nama << " dan matkul " << s.nama_matkul << " tidak ada di dalam list" << endl;
        }
    }else{
        cout << "Relasi antara dosen" << i.nama << " dan matkul " << s.nama_matkul << " tidak ada di dalam list" << endl;
    }
}
void printmat(List_r LR, List_matkul LM){
    bool stop = false;
    int i;
    clearscreen();
    cout << "Pilih apa yang akan ditampilkan dari list matkul" << endl;
    cout << "1. Print semua matkul" << endl;
    cout << "2. Print matkul dengan dosen tersedikit" << endl;
    cout << "3. Print matkul dengan dosen terbanyak" << endl;
    cout << "0. Kembali" << endl;
    do{
        cout << "Pilih menu : ";
        cin >> i;
        if(i >= 0 && i <= 3){
            stop = true;
        }else{
            cout << "Ulangi" << endl;
        }
    }while(stop != true);
    switch(i){
    case 1:
        cout << "Print semua matkul" << endl;
        clearscreen();
        printmatkul(LM);
        getch();
    break;
    case 2:

        clearscreen();
        MatkuldgnMindosen(LR, LM);
        getch();
    break;
    case 3:
        clearscreen();
        Matkuldgnmaksdosen(LR, LM);
        getch();
    break;
    }
}
void printRel(List_dosen LD,List_matkul LM,List_r LR){
    bool stop = false;
    int i;
    clearscreen();
    cout << "Pilih apa yang akan ditampilkan dari list relasi" << endl;
    cout << "1. Print semua relasi" << endl;
    cout << "2. Print matkul berdasarkan dosen tertentu" << endl;
    cout << "3. Print dosen berdasarkan matkul tertentu" << endl;
    cout << "0. Kembali" << endl;
    do{
        cout << "Pilih menu : ";
        cin >> i;
        if(i >= 0 && i <= 3){
            stop = true;
        }else{
            cout << "Ulangi" << endl;
        }
    }while(stop != true);
    switch(i){
    case 1:
        cout << "Print semua relasi" << endl;
        clearscreen();
        printrelasi(LR);
        getch();
    break;
    case 2:
        clearscreen();
        printmatkuldaridosentertentu(LR);
        getch();
    break;
    case 3:
        clearscreen();
        printdosendarimatkultertentu(
                                     LR);
        getch();
    break;
    }
}
void printmatkuldaridosentertentu(List_r &LR){
    infotypedosen D;
    cout << "Print matkul berdasarkan dosen tertentu" << endl;
    cout << "Masukkan nama dosen : ";
    cin >> D.nama;
    //cout << "Masukkan nomor telepon dosen : ";
    //cin >> D.no_telp;
    if(first(LR) != nil && last(LR) != nil){
        adr_relasi q = first(LR);
        int j = 1;
        while(q != nil){
            if(info(addressDosen(q)).nama == D.nama /*&& info(addressDosen(q)).no_telp == D.no_telp*/){
                cout << "Matkul " << j << "." << endl;
                cout << "Nama Matkul : " << info(addressMatkul(q)).nama_matkul<< endl;
                cout << "Deskripsi : " << info(addressMatkul(q)).deskripsi << endl;
                j++;
            }
            q = next(q);
        }
        if(j == 1){
            cout << "Dosen " << D.nama << " tidak mengajar" << endl;
        }
    }else{
        cout << "List relasi kosong" << endl;
    }
    /*clearscreen();
    adr_matkul M=first(LM);
    infotypedosen D;
    cout << "Print matkul berdasarkan dosen tertentu" << endl;
    cout << "Masukkan nama dosen : ";
    cin >> D.nama;
    cout << "Masukkan nomor telepon dosen : ";
    cin >> D.no_telp;
    while (M!=NULL){
        cout<<"Nama Matkul : "<<info(M).nama_matkul<<endl;
        adr_relasi P = first(LR);
        while (P!=NULL){
            if(info(P).addressMatkul==M){
                cout<<"Nama Dosen "<<info(P).addressDosen->info.nama<<endl;
                cout<<"No telp :"<<info(P).addressDosen->info.no_telp<<endl;
            }
            P=next(P);
        }
        M=next(M);
    }*/

}
void printdosendarimatkultertentu(List_r &LR){
    infotypematkul M;
    cout << "Print Dosen berdasarkan matkul tertentu" << endl;
    cout << "Masukkan nama matkul: ";
    cin >> M.nama_matkul;
    //cout << "Masukkan deskripsi matkul: ";
    //cin >> M.deskripsi;
    if(first(LR) != nil && last(LR) != nil){
        adr_relasi q=first(LR);
        int j = 1;
        while(q != nil){
            if(info(addressMatkul(q)).nama_matkul == M.nama_matkul /*&& info(addressMatkul(q)).deskripsi == M.deskripsi*/){
                cout << "Dosen " << j << "." << endl;
                cout << "Nama Dosen : " << info(addressDosen(q)).nama << endl;
                cout << "Nomor telepon Dosen : " << info(addressDosen(q)).no_telp << endl;
                j++;
            }
            q = next(q);
        }
        if(j == 1){
            cout<<"Tidak ada dosen yang mengajar" << "Matkul " << M.nama_matkul << endl;
        }
    }else{
        cout << "List relasi kosong" << endl;
    }/*
    clearscreen();
    adr_dosen D=first(LD);
    while (D!=NULL){
        cout<<"Nama Dosen : "<<info(D).nama<<endl;
        adr_relasi P = first(LR);
        while (P!=NULL){
            if(info(P).addressDosen==D){
                cout<<"Nama Matkul "<<info(P).addressMatkul->info.nama_matkul<<endl;
                cout<<"deskripsi :"<<info(P).addressMatkul->info.deskripsi<<endl;
            }
            P=next(P);
        }
        D=next(D);
    }*/
}

void Matkuldgnmaksdosen(List_r LR, List_matkul LM){
    if(first(LR) != nil && first(LM)){
        int maxx,i;
        adr_matkul q = first(LM);
        adr_matkul address_max = first(LM);
        while(q != nil){
            infotypematkul M;
            M.nama_matkul = info(q).nama_matkul;
            M.deskripsi = info(q).deskripsi;
            i = Hitungdosendarimatkul(LR, M);
            if(q == first(LM)){
                maxx = i;
            }else if(i > maxx){
                maxx = i;
                address_max = q;
            }
            q = next(q);
        }
        cout << "Matkul dengan dosen terbanyak : " << info(address_max).nama_matkul << endl;
        cout << "Dengan jumlah dosen " << maxx << endl;
    }else{
        cout << "List Matkul kosong" << endl;
    }
}
void MatkuldgnMindosen(List_r LR, List_matkul LM){
    if(first(LR) != nil && first(LM)){
        int minn,i;
        adr_matkul q = first(LM);
        adr_matkul address_min = first(LM);
        while(q != nil){
            infotypematkul M;
            M.nama_matkul = info(q).nama_matkul;
            M.deskripsi = info(q).deskripsi;
            i = Hitungdosendarimatkul(LR, M);
            if(q == first(LM)){
                minn = i;
            }else if(i < minn){
                minn = i;
                address_min = q;
            }
            q = next(q);
        }
        cout << "Matkul dengan dosen tesedikit adalah " << info(address_min).nama_matkul << endl;
        cout << "Dengan jumlah dosen " << minn << endl;
    }else{
        cout << "List matkul kosong" << endl;
    }
}
int Hitungmatkuldaridosen(List_r L, infotypedosen D){
    if(first(L) != nil && last(L) != nil){
        adr_relasi q = first(L);
        int i = 0;
        while(q != nil){
            if(info(addressDosen(q)).nama == D.nama && info(addressDosen(q)).no_telp == D.no_telp){
                i++;
            }
            q = next(q);
        }
        return i;
    }else{
        return 0;
    }
}
int Hitungdosendarimatkul(List_r L, infotypematkul M){
    if(first(L) != nil && last(L) != nil){
        adr_relasi q = first(L);
        int i = 0;
        while(q != nil){
            if(info(addressMatkul(q)).nama_matkul == M.nama_matkul && info(addressMatkul(q)).deskripsi == M.deskripsi){
                i++;
            }
            q = next(q);
        }
        return i;
    }else{
        return 0;
    }
}
