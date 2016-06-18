#ifndef CGAMEDATA_H
#define CGAMEDATA_H
#include <time.h>

typedef struct _STAGE_INFO {
	int      nBlockCount; // 벽돌 개수
	clock_t  LimitTime;  // 제한 시간
} STAGE_INFO;

class CGameData{
private:
	int	 Stage;
	int Grade;
	int	 TotalGrade;
	int * BlockState;
	int BlockCount;
	STAGE_INFO  * StageInfo;
	clock_t GameStartTime, UpdateOldTime, RemainTime;
public:
	CGameData();
	~CGameData();
	
	void Init();

	void setStage(int Stage);
	void setGrade(int Grade);
	void setTotalGrade(int TotalGrade);
	void setGameStartTime(clock_t GameStartTime);
	void setUpdateOldTime(clock_t UpdateOldTime);
	void setRemainTime(clock_t RemainTime);
	void setBlockCount(int BlockCount);

	int getStage();
	int getGrade();
	int getTotalGrade();
	int * getBlockState();
	int getBlockCount();

	clock_t getGameStartTime();
	clock_t getUpdateOldTime();
	clock_t getRemainTime();
	STAGE_INFO * getStageInfo();
};
#endif