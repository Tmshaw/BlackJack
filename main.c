#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/***********************************************************
*                  Structs for Players                     *
***********************************************************/
struct player {
    int how_many;
    int *hand;
};

struct dealer {
    int remaining_cards;
    int *deck;
    int *cards;
    struct player *dealer_type;
};

/**************************************************************************
*Functions for Hit, Draw, Bust, Shuffle, BlackJack, Display, Victory, Deal*
**************************************************************************/
int victory(struct player *temp) {
    int victory = 0;
    
    if(bust(temp)!=1)
    {
        if(temp->how_many==5)
        {
            victory=1;
        }
    }
    
    return victory;
}

void display(struct player *temp) {
    int i;
    
    for(i=0;i<5;i++)
    {
        if(temp->hand[i])
        {
            printf("%d ", temp->hand[i]);
        }
        
    }
}

void shuffle(struct player *p1, struct player *p2, struct dealer *temp) {
    int i;
    
    for(i=0;i<52;i++)
    {
        temp->deck[i] = i + 1;
        temp->cards[i] = 0;
    }
    
    for(i=0;i<52;i++)
    {
        while(temp->deck[i]>13)
        {
            temp->deck[i] -= 13;
        }
        if(temp->deck[i]>9)
        {
            temp->deck[i] = 10;
        }
        if(temp->deck[i] == 1)
        {
            temp->deck[i] = 11;
        }
    }
}

void deal(struct player *player1, struct player *player2, struct dealer *playerD) {
    int x, l, y, tempo;
    
    
    l = 0;
    y = 0;
    
    
    while (y<6)
    {
        switch (y)
        {
            case 0:
            {
                tempo = 1;
                
                while (tempo)
                {
                    x = rand();
                    x %= 52;
                
                    if(playerD->cards[x]==0)
                    {
                        player1->hand[l] = playerD->deck[x];
                        playerD->cards[x] = 1;
                        player1->how_many++;
                        y++;
                        tempo = 0;
                    }
                }
            }
            break;
            
            
            
            case 1:
            {
                tempo = 1;
                
                while(tempo)
                {
                    x = rand();
                    x = x%52;
                    
                    if(playerD->cards[x]==0)
                    {
                        player2->hand[l] = playerD->deck[x];
                        playerD->cards[x] = 1;
                        player2->how_many++;
                        y++;
                        tempo = 0;
                    }
                }
            }
            break;
            
            
            
            case 2:
            {
                tempo = 1;
                
                while(tempo)
                {
                    x = rand();
                    x = x%52;
                
                    if(playerD->cards[x]==0)
                    {
                        playerD->dealer_type->hand[l] = playerD->deck[x];
                        playerD->cards[x] = 1;
                        playerD->dealer_type->how_many++;
                        y++;
                        l++;
                        tempo = 0;
                    }
                }
            }
            break;
            
            
            
            case 3:
            {
                tempo = 1;
                
                while(tempo)
                {
                    x = rand();
                    x = x%52;
                
                    if(playerD->cards[x]==0)
                    {
                        player1->hand[l] = playerD->deck[x];
                        playerD->cards[x] = 1;
                        player1->how_many++;
                        y++;
                        tempo = 0;
                    }
                }
            }
            break;
            
            
            
            case 4:
            {
                tempo = 1;
                
                while(tempo)
                {
                    x = rand();
                    x = x%52;
                
                    if(playerD->cards[x]==0)
                    {
                        player2->hand[l] = playerD->deck[x];
                        playerD->cards[x] = 1;
                        player2->how_many++;
                        y++;
                        tempo = 0;
                    }
                }
            }
            break;
            
            
            
            case 5:
            {
                tempo = 1;
                
                while(tempo)
                {
                    x = rand();
                    x = x%52;
                
                    if(playerD->cards[x]==0)
                    {
                        playerD->dealer_type->hand[l]  = playerD->deck[x];
                        playerD->cards[x] = 1;
                        playerD->dealer_type->how_many++;
                        y++;
                        tempo = 0;
                    }
                }
            }
            break;
        }
    }
}

int anotha_one() {
    int k;
    
    printf("If you wish to play again, enter 1\nElse enter any other number.\n");
    scanf("%d", &k);
    
    return k;
}

int sum(struct player *temp) {
    int i, sum;
    sum = 0;
    
    for(i=0;i<5;i++)
    {
        sum += temp->hand[i];
    }
    
    return sum;    
}

int blackjack(struct player *temp) {
    int bjack, luck;
    bjack = 0;
    
    luck = sum(temp);
    
    if(luck == 21)
    {
        printf("Congratulations. You have won with BlackJack\n");
        bjack = 1;
    }
    
    return bjack;
}

int bust(struct player *temp) {
    int i, busted;
    
    busted=0;
    
    if(sum(temp)>21)
    {
        for(i=0;i<5;i++)
        {
            if(temp->hand[i]==11)
            {
                temp->hand[i]=1;
            }
        }
        if(sum(temp)>21)
        {
            display(temp);
            busted=1;
        }
        
    }
    
    return busted;
}

void hit(struct player*temp, struct dealer*temp1) {
    srand(time(NULL));
    int i, j = 0;
    if(temp1 -> remaining_cards != 0) {
        int v = rand() % 52;
        if(temp1 -> cards[v] == 0) {
            
        }
    }
    for(i=0; i<52; i++) {
        j = j + temp1 -> deck[i];
    }
    if(j != 0) {
        
    }
}

/****************
* Main Function *
****************/
int main()
{
    int i, suite, remain;
    char p1[31], p2[31];
    
    
    
    printf("Player 1, what's you're name?\n(max of 30 characters)\n");
    scanf("%s", p1);
        
    printf("Player 2, what's you're name?\n(max of 30 characters)\n");
    scanf("%s", p2);
    
    
    
    //Individual victories
    int p1_victories = 0;
    int p2_victories = 0;
    int dealer_victories = 0;
    int p1_ties = 0;
    int p2_ties = 0;
    int dealer_ties = 0;
    
    
    
    
    do
    {
   
        int *deck = malloc(sizeof(int)*52);
        int *used = malloc(sizeof(int)*52);
        remain = 52;
        
        for(i=0;i<52;i++)
        {
            deck[i] = i+1;
            used[i] = 1;
        }

        printf("%s and %s\n", p1, p2);
        
        int *initial_hand_p1 = malloc(sizeof(int)*6);
        int *initial_hand_p2 = malloc(sizeof(int)*6);
        int *initial_hand_dealer = malloc(sizeof(int)*6);
        int initial_cards_held = 0; 

    

        //initializing structures
    
        struct player player_1 = {initial_hand_p1, initial_cards_held};
        struct player player_2 = {initial_hand_p2, initial_cards_held};
        struct player player_3 = {initial_hand_dealer, initial_cards_held};
        
        //denoting pointers
        
        struct player *dealer_type = &player_3;
        struct player *p1 = &player_1;
        struct player *p2 = &player_2;
        
        struct dealer HOUSE = {deck, used, remain, dealer_type};
        
        
        //Calling the functions
        
        shuffle(p1, p2, &HOUSE);
        deal(p1, p2, &HOUSE);
        
        
        
        
        
        
        
        int lop=1;
        
        while(lop)
        {
            if(blackjack(p1))
            {
                printf("%s has got blackjack!", p1);
                p1_victories++;
                break;
            }
            if(blackjack(p2))
            {
                printf("%s has got blackjack!", p2);
                p2_victories++;
                break;
            }
            if(blackjack(dealer_type))
            {
                printf("The dealer has got blackjack!");
                dealer_victories++;
                break;
            }
            
            
            int decision;
            
            printf("\n%s, your cards are:\n", p1);
            display(p1);
            printf("\nTo hit, enter 1: Stand, 0\n");
            scanf("%d", &decision);
            
            while(decision==1)
            {
                hit(p1, &HOUSE);
                if(bust(p1))
                {
                    printf("\n%s, you busted with the cards:\n", p1);
                    break;
                }
                else if(victory(p1))
                {
                    break;
                }
                printf("\nTo hit, enter 1: Stand, 0\n");
                scanf("%d", &decision);
            }
            if(victory(p1))
            {
                printf("%s is victorious!\n", p1);
                p1_victories++;
                break;
            }
            
            
            
            
            printf("\n\n%s, your cards are:\n", p2);
            display(p2);
            printf("\nTo hit, enter 1: Stand, 0\n");
            scanf("%d", &decision);
            
            while(decision==1)
            {
                hit(p2, &HOUSE);
                if(bust(p2))
                {
                    printf("\n%s, you busted with the cards:\n", p2);
                    break;
                }
                if(victory(p2))
                {
                    break;
                }
                printf("\nTo hit, enter 1: Stand, 0\n");
                scanf("%d", &decision);
            }
            if(victory(p2))
            {
                printf("%s is victorious!\n", p2);
                p2_victories++;
                break;
            }
            
            
            
            /*******************************************************************
             * This next part adds the rule that the dealer must hit if under 16
             * *****************************************************************/
            printf("\nNow the dealer goes\n");
            
            if(sum(dealer_type)>15)
            {
                printf("He stands.\n");
            }
            while(sum(dealer_type)<16)
            {
                
                
                if((sum(p1)==sum(p2))&&(sum(p1)==0)&&(sum(p2)==0))
                {
                    printf("The dealer has stood.\n");
                    break;
                }
                
                
                hit(dealer_type, &HOUSE);
                if(bust(dealer_type))
                {
                    printf("The dealer has busted:\n");
                }
                if(victory(dealer_type))
                {
                    break;
                }
            }
            if(victory(dealer_type))
            {
                printf("The dealer is victorious!\n");
                dealer_victories++;
                break;
            }
            
            int q, w, e;
            q = sum(p1);
            w = sum(p2);
            e = sum(dealer_type);
            
            if(q>21)
                q=0;
            if(w>21)
                w=0;
            if(e>21)
                e=0;
            
            printf("\n%s had a total of %d.\n%s had a total of %d.\nThe dealer had a total of %d.\nA zero as the total indicates a bust\n\n", p1, q, p2, w, e);
            
            
            
            if(q>w && q>e)
            {
                printf("%s has won this round.\n", p1);
                p1_victories++;
            }
            if(w>q && w>e)
            {
                printf("%s has won this round.\n", p2);
                p2_victories++;
            }
            if(e>q && e>w)
            {
                printf("The HOUSE has won this round.\n");
                dealer_victories++;
            }
            if((q==w)&&(q>e)&&(w>e))
            {
                printf("%s and %s have tied for victory this round.\n", p1, p2);
                p1_ties++;
                p2_ties++;
            }
            if((q==e)&&(q>w)&&(e>w))
            {
                printf("%s and the dealer hav tied for victory this round.\n", p1);
                dealer_ties++;
                p1_ties++;
            }
            if((w==e)&&(w>q)&&(e>q))
            {
                printf("%s and the dealer has won this round.\n", p2);
                dealer_ties++;
                p2_ties++;
            }
            if((w==e)&&(w==q)&&(w>0))
            {
                printf("Everyone has tied for victory this round.\n");
                dealer_ties++;
                p1_ties++;
                p2_ties++;
            }
            
            
            
            lop = 0;
        
        }
        
        
        /***********************************************************************
         * this loop resets the higher card values so that each new round does 
         * not start the player/dealer with more than 2 cards.
         * *********************************************************************/
        for(i=0;i<5;i++)
        {
            p1->hand[i] = 0;
            p2->hand[i] = 0;
            dealer_type->hand[i] = 0;
        }
        free(deck);
        free(used);
        free(initial_hand_p1);
        free(initial_hand_p2);
        free(initial_hand_dealer);
    }
    while(anotha_one()==1);
    

    int check_stats;
    printf("Enter a 1 if you would like to see the game stats: any other number, if not.\n");
    scanf("%d", &check_stats);
    if(check_stats)
    {
        printf("%s had %d victories and %d ties.\n", p1, p1_victories, p1_ties);
        printf("%s had %d victories and %d ties.\n", p2, p2_victories, p2_ties);
        printf("The dealer had %d victories and %d ties.\n", dealer_victories, dealer_ties);
    }

    printf("Thank you for playing\nAnd may luck always follow you.");
    return 0;
    
}



