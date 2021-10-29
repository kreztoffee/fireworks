#ifndef __TIME_FW_H__
#define __TIME_FW_H__

#define MS_PER_UPDATE 20

struct time_fw {
	double prev_ms;
	double lag;
	double cur_ms;
	double delta_ms;
};

struct time_fw* init_time_fw();
void step_time_fw(struct time_fw* time_fw);
void print_time_fw(struct time_fw* time_fw);

#endif /* __TIME_FW_H__ */
