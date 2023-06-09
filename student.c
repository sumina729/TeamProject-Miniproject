#include "student.h"
#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생용 기능 여기서 만들기 + 서브매인도.
// 헤더는 (void student_main())는 무조건 헤더파일에 선언해주어야 합니다.
// * students[] 변수와, count 변수는 헤더에 글로벌변수로 선언 되어 있기에 그냥
// 변수 쓰시면 오류 안나고 사용 가능. 또한, 전역 변수여서  함수 만들때
// 파라매터로 주지 한고 그냥 사용 가능
// * students[] 변수는 malloc을 이용해서 메모리 할당 해줘야 합니다.
// count 변수는 main.c 에서 0으로 초기화 했으니 사용 하시면 됩니다!

void student_main() {
  while (1) {
    int menu = 0;
    printf("\n---학생용 기숙사 신청 시스템---\n");
    printf("1. 본인 정보 확인하기. \n");
    printf("2. 기숙사 신청하기. \n");
    printf("3. 기숙사 신청 수정하기. \n");
    printf("4. 기숙사 신청 취소하기. \n");
    printf("5. 외박 신청하기. \n");
    printf("6. 메인 화면으로\n");
    printf("----------------------\n");

    printf("원하는 메뉴를 입력하세요 > ");
    scanf("%d", &menu);

    if (menu == 6)
      break;
    if (menu == 1) {
      checkMyInfo();
    } else if (menu == 2) {
      apply_domitory();
    } else if (menu == 3) {
      update_domitory();
    } else if (menu == 4) {
      delete_domitory();
    } else if (menu == 5) {
      apply_overnight();
    } else {
      printf("\n!!입력오류!!\n");
      printf("!!다시 입력해주세요!!\n");
    }
  }

  //여기에 기능 메뉴 만들어서 기능 사용.
  //여기서 return 하면 메인으로 돌아가짐.
  return;
}

//여기 밑에 각 기능을 위한 함수 구현. 헤더파일에 헤더부분 꼭 선언 해야 오류
//안남.
void checkMyInfo() {
  char id[20];   // 직접 입력하게 될 ID
  char name[20]; // 직접 입력하게 될 Name
  int k = 100;     // 학생이 몇번인지 확인하기 위한 변수
  printf("학번을 입력하시오. "); //학번 입력
  scanf("%s", id);

  for (int i = 0; i < count; i++) {
    if (strcmp(id, students[i]->s_ID) ==0) { // 입력한 학번과 일치하는 학번이 있는지 확인
      k = i;
      break;
    }
  }

  if(k==100){
    printf("입력하신 학번이 존재하지 않습니다. \n");
  }

  else{
    printf("이름을 입력하시오. "); // 이름을 입력받기
    scanf("%s", name);

    if (strcmp(name, students[k]->name) == 0) { //입력받은 이름과 학번이 일치하면 본인의 개인정보 공개
      printf("********************\n");
      printf("이름 : %s\n", students[k]->name);
      printf("학번 : %s\n", students[k]->s_ID);
      printf("성별 : %s\n", students[k]->f_m);
      printf("기숙사 : %s\n", students[k]->Dormitory_name);
      printf("인실 : %d\n", students[k]->total_num_room);
      if(students[k]->Y_N == 'N'){
        printf("호실 : 아직 방 배정이 되지 않았습니다.\n");
      }
      else{
        printf("호실 : %d\n", students[k]->room_num);
      }
      printf("벌점 : %d\n", students[k]->demerit);
      printf("********************\n");
    } else { //이름과 학번이 일치하지 않는 경우
      printf("정보가 존재하지 않습니다. 다시 입력해주세요.\n");
    }
  }
}

void apply_domitory() {
  students[count] = (student *)malloc(sizeof(student)); //======> main에서 여기 함수로 옮김.
  printf("이름을 입력하시오. ");
  scanf("%s", students[count]->name);
  printf("학번을 입력하시오. ");
  scanf("%s", students[count]->s_ID);
  printf("성별을 입력하시오. ");
  scanf("%s", students[count]->f_m);
  printf("건물 이름을 입력하시오. (건물의 풀 네임으로 입력해주세요. ex) 로뎀관, 은혜관.). ");
  scanf("%s", students[count]->Dormitory_name);
  printf("몇인실을 신청하실 건가요? (창조관은 1인실, 갈대상자관은 1인실/2인실, 나머지 호관은 4인실/2인실이 신청 가능합니다.). ");
  scanf("%d", &students[count]->total_num_room);

  students[count]->demerit = 0; //======> 이부분 추가
  students[count]->Y_N = 'N'; //======> 이부분 추가
  students[count]->num = 0;

  printf("\n신청 성공!\n");
  count++;
}

void update_domitory() {
  char id[20];   // 직접 입력하게 될 ID
  char name[20]; // 직접 입력하게 될 Name
  int k = 0;     // 학생이 몇번인지 확인하기 위한 변수
  printf("학번을 입력하시오. (처음 입력했던대로 입력하시오) "); //학번 입력
  scanf("%s", id);

  for (int i = 0; i < count; i++) {
    if (strcmp(id, students[i]->s_ID) ==
        0) { // 입력한 학번과 일치하는 학번이 있는지 확인
      k = i;
      break;
    }
  }

  printf("이름을 입력하시오. (처음 입력했던대로 입력하시오) "); // 이름을 입력받기
  scanf("%s", name);

  if(students[k]->Y_N=='Y'){
    printf("기숙사 신청이 완료되어 삭제가 불가능합니다.\n");
  }

  else{
    if (strcmp(name, students[k]->name) == 0) {
      printf("이름을 입력하시오. ");
      scanf("%s", students[k]->name);
      printf("학번을 입력하시오. ");
      scanf("%s", students[k]->s_ID);
      printf("성별을 입력하시오. ");
      scanf("%s", students[k]->f_m);
      printf("건물 이름을 입력하시오. (건물의 풀 네임으로 입력해주세요. ex) 로뎀관, 은혜관.) ");
      scanf("%s", students[k]->Dormitory_name);
      printf("몇인실을 신청하실 건가요? (창조관은 1인실, 갈대상자관은 1인실/2인실, 나머지 호관은 4인실/2인실이 신청 가능합니다.) ");
      scanf("%d", &students[k]->total_num_room);
    }
    printf("수정 성공!\n");
  }
}

void delete_domitory() {
  char id[20];   // 직접 입력하게 될 ID
  char name[20]; // 직접 입력하게 될 Name
  int num = 0;
  int k = 100; // 학생이 몇번인지 확인하기 위한 변수
  printf("학번을 입력하시오. (처음 입력했던대로 입력하시오) "); //학번 입력
  scanf("%s", id);

  for (int i = 0; i < count; i++) {
    if (strcmp(id, students[i]->s_ID) ==
        0) { // 입력한 학번과 일치하는 학번이 있는지 확인
      k = i;
      break;
    }
  }

  if(k==100){
    printf("입력하신 학번이 존재하지 않습니다. \n");
  }

  printf("이름을 입력하시오. (처음 입력했던대로 입력하시오) "); // 이름을 입력받기
  scanf("%s", name);

  if(students[k]->Y_N=='Y'){
    printf("기숙사 신청이 완료되어 삭제가 불가능합니다.\n");
  }

  else{
    if (strcmp(name, students[k]->name) == 0) {
      printf("정말로 삭제하시겠습니까?(삭제 :1) ");
      scanf("%d", &num);
      if (num == 1) {
        char a[20] = "\0";
        strcpy(students[k]->name, a);
        strcpy(students[k]->s_ID, a);
        strcpy(students[k]->f_m, a);
        strcpy(students[k]->Dormitory_name, a);
        students[k]->total_num_room = -1;
        printf("삭제 성공!\n");
      }
    }
    }
}

void apply_overnight(){
  char id[20];   // 직접 입력하게 될 ID
  char name[20]; // 직접 입력하게 될 Name
  int num = 0;
  int k = 100; // 학생이 몇번인지 확인하기 위한 변수
  printf("학번을 입력하시오. (처음 입력했던대로 입력하시오) "); //학번 입력
  scanf("%s", id);

  for (int i = 0; i < count; i++) {
    if (strcmp(id, students[i]->s_ID) ==
        0) { // 입력한 학번과 일치하는 학번이 있는지 확인
      k = i;
      break;
    }
  }
  
  if(k==100){
    printf("입력하신 학번이 존재하지 않습니다. \n");
  }

  else{
    printf("이름을 입력하시오. (처음 입력했던대로 입력하시오) "); // 이름을 입력받기
    scanf("%s", name);
    
    if(strcmp(name, students[k]->name) == 0){
      printf("외박을 신청하실 날짜를 입력하시오. ( 예시: 5.18 ) ");
      scanf("%s", overnight.overnight_date);

      printf("외박신청사유를 입력하시오. ");
      scanf("%s", overnight.overnight_reason);

      students[k]->overnight_staystudent_overnight_list[students[k]->num] = overnight;
      students[k]->num++;

      printf("외박 신청이 완료되었습니다! \n");
    }
    else{
      printf("이름이 잘못 입력되었습니다.\n");
    }
  }
}
