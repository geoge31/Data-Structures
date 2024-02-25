/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Antonios Peris                         *
 * @Version 20-10-2020                             *
 * @email   csdp1196@csd.uoc.gr                    *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */


#include "among_us.h"

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {

 players_head = NULL;
 tasks_head = NULL;
 tasks_stack = NULL;   
    
    return 1;
}

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid,int is_alien) {

    struct Players *new_Player;
    new_Player = (struct Players*)malloc(sizeof(struct Players));

    new_Player -> pid = pid;
    new_Player -> is_alien = is_alien;

    if(players_head==NULL) {

        players_head = new_Player;
        new_Player -> prev = players_head;
        new_Player -> next = players_head;
    }

    else {

        new_Player -> next = players_head;
        players_head -> next -> prev = new_Player;
        new_Player -> prev = players_head;
        players_head = new_Player; 
    }

    print_players();
  
    return 1;
}

/**
 * @brief Insert task in the general task list
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid,int difficulty) {

    struct Tasks *new_task;
    new_task = (struct Tasks*)malloc(sizeof(struct Tasks));

    new_task -> tid = tid;
    new_task -> difficulty = difficulty;

    if(tasks_head==NULL){

        tasks_head = new_Task;
		new_Task -> next = NULL;
         
    }

    else{

        struct Tasks *tmp;
        tmp = (struct Tasks*)malloc(sizeof(struct Tasks));

		tmp = tasks_head;

		while(tmp -> next != NULL) {

			if(new_Task -> difficulty > tmp -> difficulty && new_Task -> difficulty < tmp -> next -> difficulty) {

				new_Task = tmp -> next;

				tmp -> next = new_Task;
    }

    print_tasks();

    return 1;
}

/**
 * @brief Distribute tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {

    struct Players *dis_player;
    struct Tasks *dis_tasks;

    dis_player = (struct Payers*)malloc(sizeof(struct Players));
    dis_tasks = (struct Tasks*)malloc(sizeof(struct Tasks));

    dis_ player = players_head;
    dis_tasks = tasks_head;

    while(dis_player -> next != players_head && dis_tasks -> next != NULL){



        if(dis_player->is_alien==1){
            dis_player = dis_player -> next;
        }
    }


    return 1;
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty) {

    struct Players *I_player,*find_PLayer;
    I_player = (struct Players*)malloc(sizeof(struct Players));
    find_player =  (struct Players*)malloc(sizeof(struct Players));

    find_player = players_head;

    I_player -> pid = pid;
    I_player -> difficulty = difficulty;

    while(find_player -> next = players_head) {

        if(find_player -> pid != I_player -> pid) {
             find_player = find_player -> next;
        }

        // find the task
        // push to stack
    }



    


    return 1;
}

/**
 * @brief Eject Player
 * 
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid) {
    return 1;
}

/**
 * @brief Witness Eject Player
 *
 * @param pid_a The alien's pid
 * 
 * @param pid The crewmate's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid, int pid_a, int number_of_witnesses){
    return 1;
}


/**
 * @brief Sabbotage
 *
 * @param pid The player's id
 *
 * @param number_of_tasks The number of tasks to be popped
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabbotage(int pid, int number_of_tasks) {
    return 1;
}


/**
 * @brief Vote
 *
 * @param pid The player's id
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid, int vote_evidence) {
    return 1;
}


/**
 * @brief Give Away Work
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work() {
    return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
    return 1;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {

    struct Players *dummy;
    dummy = (struct Players*)malloc(sizeof(struct Players));

    dummy = players_head;
        
    DPRINT("Players= ");
    while(dummy -> next != players_head){

        if(dummy -> pid != -1) {

            DPRINT("<pid%d:is_alien:%d>",dummy -> pid, dummy -> is_alien);
            dummy = dummy -> next;
        }
        else {
            dummy = dummy -> next;
        }
    }

    DPRINT("\n");

    return 1;
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {

    struct Tasks *dummy2;
    dummy2 = (struct Tasks*)malloc(sizeof(struct Tasks));

    dummy2 = tasks_head;

    DPRINT("Tasks =");
    while(dummy2 -> next != NULL){

        DPRINT("<tid%d,difficulty%d",dummy2 -> tid, dummy2 -> difficulty);

        dummy2 = dummy2 -> next;

    } 

    DPRINT("\n");
    
    return 1;
}

/**
 * @brief Print Stack
 *
 * @return 1 on success
 *         0 on failure
 */
int print_stack() {
    return 1;
}

/**
 * @brief Print Players & Task List
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_list() {
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void) {
    return 1;
}
