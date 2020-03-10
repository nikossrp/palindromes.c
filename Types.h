//stiva me listes
typedef char ItemType;

typedef struct StackNodeTag{    //mporoume me allon tropo na elenxoume an einai kenh h oxi (NULL)
   ItemType Item;
   struct StackNodeTag * Link;

}StackNode;

//h stoiva stin ousia einai enas deikths sto prwto stoixeio tis stoivas
typedef struct{     //h stoiva
   StackNode* ItemList; 
}Stack;