struct nodeFB {
    int id;
    int age;
    struct nodeFB *next;
};

struct nodeGS {
    int id;
    struct nodeGS *next;
};

struct newNodeFB {
    int id;
    int age;
    struct newNodeFB *next; 
};

struct newNodeGS {
    int id;
    struct newNodeFB *next; 
};

void insertFB(struct nodeFB **head, int id, int age) {
    struct nodeFB *newNode = (struct nodeFB*)malloc(sizeof(struct nodeFB));
    newNode->id = id;
    newNode->age = age;
    newNode->next = NULL;

    if (*head == NULL || (*head)->id > id) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct nodeFB *current = *head;
        while (current->next != NULL && current->next->id < id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertGS(struct nodeGS **head, int id) {
    struct nodeGS *newNode = (struct nodeGS*)malloc(sizeof(struct nodeGS));
    newNode->id = id;
    newNode->next = NULL;

    if (*head == NULL || (*head)->id < id) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct nodeGS *current = *head;
        while (current->next != NULL && current->next->id > id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printFB(struct nodeFB *head) {
    while (head != NULL) {
        printf("%d %d\n", head->id, head->age);
        head = head->next;
    }
}

void printGS(struct nodeGS *head) {
    while (head != NULL) {
        printf("%d\n", head->id);
        head = head->next;
    }
}

void createFinalList(struct newNodeFB **finalHead, struct nodeFB *fbHead, struct nodeGS *gsHead) {
    struct newNodeFB *currentFB = NULL;
    while (fbHead != NULL && gsHead != NULL) {
        // Fenerbahçe taraftarını yeni listeye aliyoruz
        struct newNodeFB *fbNode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
        fbNode->id = fbHead->id;
        fbNode->age = fbHead->age;
        fbNode->next = NULL;

        if (*finalHead == NULL) {
            *finalHead = fbNode;
        } else {
            currentFB->next = fbNode;
        }
        currentFB = fbNode;

        // Galatasaray taraftarını yeni listeye aliyoruz
        struct newNodeFB *gsNode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
        gsNode->id = gsHead->id;
        gsNode->age = -1;  // `age` alanı GS taraftarları için geçersiz, bu yüzden -1 atanabilir
        gsNode->next = NULL;
        currentFB->next = gsNode;

        // Bir sonraki düğümü işaret etmesi için currentFB'yi ayarlıyoruz
        currentFB = gsNode;

        // Diğer düğümler
        fbHead = fbHead->next;
        gsHead = gsHead->next;
    }
}


void printAll(struct newNodeFB *head) {
    while (head != NULL) {
        if (head->age != -1) {
            printf("%d %d\n", head->id, head->age);
        } else {
            printf("%d\n", head->id);
        }
        head = head->next;
    }
}



    


// Bu lab kapsaminda kullanilacak butun fonksiyon tanimlarini bu dosyanin icine yazmaniz gerekmektedir.
// Tanimlanmasi zorunlu fonksiyonlar icerisinden kendi tanimayacaginiz baska fonksiyonlari cagirabilirsiniz.
// main.c dosyasinda bir degisiklik yapmayiniz.
// Sisteme function.h dosyasinin ismini OgrenciNumarasi.h olarak yukleyiniz.


