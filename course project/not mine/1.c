#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int code;
    char name[50];
    float price;
    int stock;
    int date_received[3];
    int expiration_date[3];
};

struct node {
    struct product data;
    struct node* left;
    struct node* right;
};
int mm,yy,dd;
struct node* insert(struct node* root, struct product data);
//void list_expired_items_prefix(struct node* root);
void list_all_items(struct node* root);
struct node* delete_by_code(struct node* root, int code);
//struct node* delete_expired_items(struct node* root);

int main() {
    struct node* root = NULL;
    int choice, code;
    struct product data;
    printf("Shop Owner Program\n");
    do {
        printf("\nMenu\n1. Insert an item\n2. List all items\n3. Delete an item\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Date Received (YYYY\\MM\\DD): ");
                scanf("%d", &yy);
                if(yy>=1900 && yy<=9999){
                    //check month
                    scanf("%d", &mm);
                    if(mm>=1 && mm<=12){
                        scanf("%d", &dd);
                        if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                            data.date_received[0] = dd;
                            data.date_received[1] = mm;
                            data.date_received[2] = yy;
                        }
                        else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                            data.date_received[0] = dd;
                            data.date_received[1] = mm;
                            data.date_received[2] = yy;
                        }
                        else if((dd>=1 && dd<=28) && (mm==2)){
                            data.date_received[0] = dd;
                            data.date_received[1] = mm;
                            data.date_received[2] = yy;
                        }
                        else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                            data.date_received[0] = dd;
                            data.date_received[1] = mm;
                            data.date_received[2] = yy;
                        }
                        else{
                            printf("Day is invalid.\n");
                            break;
                        }
                        }else{
                        printf("Month is not valid.\n");
                        break;
                    }
                }else{
                    printf("Year is not valid.\n");
                    break;
                }
                printf("Expiration Date (YYYY\\MM\\DD): ");
                scanf("%d", &yy);
                if(yy>=1900 && yy<=9999){
                    //check month
                    scanf("%d", &mm);
                    if(mm>=1 && mm<=12){
                        scanf("%d", &dd);
                        if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                            if (data.date_received[2] > yy)
  { printf("invalid expiration date");
    break;
  }
else
  {
    if (data.date_received[2] == yy)
      {
if (data.date_received[1] > mm)
 {
   printf("invalid expiration date");
   break;
 }
else
 {
   if (data.date_received[1] == mm)
     {
if (data.date_received[0] >= dd)
 {
    printf("invalid expiration date");
   break;
 }
else
 {
   continue;/*if (data.date_received[0] == dd)
     {

     }*/
 }

     }
 }

      }
  }

                            data.expiration_date[0] = dd;
                            data.expiration_date[1] = mm;
                            data.expiration_date[2] = yy;
                        }
                        else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                            if (data.date_received[2] > yy)
  {printf("invalid expiration date");
    break;
  }
else
  {
    if (data.date_received[2] == yy)
      {
if (data.date_received[1] > mm)
 {
   printf("invalid expiration date");
   break;
 }
else
 {
   if (data.date_received[1] == mm)
     {
if (data.date_received[0] >= dd)
 {
  printf("invalid expiration date");
   break;
 }
else
 {
   continue;/*if (data.date_received[0] == dd)
     {

     }*/
 }

     }
 }

      }
  }

                            data.expiration_date[0] = dd;
                            data.expiration_date[1] = mm;
                            data.expiration_date[2] = yy;
                        }
                        else if((dd>=1 && dd<=28) && (mm==2)){
                            if (data.date_received[2] > yy)
  {
      printf("invalid expiration date");
    break;
  }
else
  {
    if (data.date_received[2] == yy)
      {
if (data.date_received[1] > mm)
 {
   printf("invalid expiration date");
   break;
 }
else
 {
   if (data.date_received[1] == mm)
     {
if (data.date_received[0] >= dd)
 { printf("invalid expiration date");
   break;
 }
else
 {
   continue;/*if (data.date_received[0] == dd)
     {

     }*/
 }

     }
 }

      }
  }

                            data.expiration_date[0] = dd;
                            data.expiration_date[1] = mm;
                            data.expiration_date[2] = yy;
                        }
                        else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                            if (data.date_received[2] > yy)
  {printf("invalid expiration date");
    break;
  }
else
  {
    if (data.date_received[2] == yy)
      {
if (data.date_received[1] > mm)
 {
   printf("invalid expiration date");
   break;
 }
else
 {
   if (data.date_received[1] == mm)
     {
if (data.date_received[0] >= dd)
 {
     printf("invalid expiration date");
   break;
 }
else
 {
   continue;/*if (data.date_received[0] == dd)
     {

     }*/
 }

     }
 }

      }
  }

                            data.expiration_date[0] = dd;
                            data.expiration_date[1] = mm;
                            data.expiration_date[2] = yy;
                        }
                        else{
                            printf("Day is invalid.\n");
                            break;
                        }
                    }else{
                        printf("Month is not valid.\n");
                        break;
                    }
                }else{
                    printf("Year is not valid.\n");
                    break;
                }
                printf("Enter item details:\nCode: ");
                scanf("%d", &data.code);
                printf("Name: ");
                scanf("%s", data.name);
                printf("Price: ");
                scanf("%f", &data.price);
                printf("Stock: ");
                scanf("%d", &data.stock);
                //scanf("%s", data.expiration_date);
                root = insert(root, data);
                break;
            case 2:
                printf("All items:\n");
                list_all_items(root);
                break;
             /*   printf("Expired items in Prefix order:\n");
                list_expired_items_prefix(root);
                break;*/
            case 3:
                printf("Enter item code to delete: ");
                scanf("%d", &code);
                root = delete_by_code(root, code);
                if(root == NULL) {
                    printf("Item not found\n");
                }
                else {
                    printf("Item deleted successfully\n");
                }
                break;
            case 4:
                printf("Exiting program\n");
                break;
             /*case 5:
               root = delete_expired_items(root);
                printf("Expired items deleted successfully\n");
                break;
            case 6:
                */
            default:
                printf("Invalid choice, try again\n");
        }
    } while(choice != 4);
    return 0;
}

struct node* insert(struct node* root, struct product data) {
    if(root == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if(data.code < root->data.code) {
        root->left = insert(root->left, data);
    }
    else if(data.code > root->data.code) {
        root->right = insert(root->right, data);
    }
    return root;
}

/*void list_expired_items_prefix(struct node* root) {
    if(root == NULL) {
        return;
    }
    if(strcmp(root->data.expiration_date, "0000-00-00") != 0) {
        printf("%s\n", root->data.name);
    }
    list_expired_items_prefix(root->left);
    list_expired_items_prefix(root->right);
}*/

void list_all_items(struct node* root) {
    if(root == NULL) {
        return;
    }
    list_all_items(root->left);
    printf("Code: %d, Name: %s, Price: %.2f, Stock: %d, Date Received: %d-%d-%d, Expiration Date: %d-%d-%d\n", root->data.code, root->data.name, root->data.price, root->data.stock, root->data.date_received[0],root->data.date_received[1],root->data.date_received[2] ,root->data.expiration_date[0],root->data.expiration_date[1],root->data.expiration_date[2]);
    list_all_items(root->right);
}

struct node* delete_by_code(struct node* root, int code) {
    if(root == NULL) {
        return NULL;
    }
    if(code < root->data.code) {
        root->left = delete_by_code(root->left, code);
    }
    else if(code >= root->data.code) {
        root->right = delete_by_code(root->right, code);
    }
    else {
        if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_by_code(root->right, temp->data.code);
    }
    return root;
}

/*struct node* delete_expired_items(struct node* root) {
    if(root == NULL) {
        return NULL;
    }
    root->left = delete_expired_items(root->left);
    root->right = delete_expired_items(root->right);
    if(strcmp(root->data.expiration_date, "0000-00-00") != 0) {
        root = delete_by_code(root, root->data.code);
    }
    return root;
}*/

