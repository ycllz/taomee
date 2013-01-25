/*
 * =====================================================================================
 * 
 *       Filename:  CtableRoute.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  2007��11��06�� 19ʱ52��58�� CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xcwen (xcwen), xcwenn@gmail.com
 *        Company:  TAOMEE
 * 
 * =====================================================================================
 */

#ifndef  CTABLEROUTE_INCL
#define  CTABLEROUTE_INCL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ctable.h"
#include <string> 



class CtableRoute : public Ctable {
	protected:
		char table_name_pre[40];
		char db_name_pre[40];
		char id_name[20];
		char key2_name[20];
		//ͨ�� id �õ�����(��ʽ�� dbname.table, ��: USER_00.t_user_pet_00 )
		// �õ��ı��������� this->tmp_table_name
		// ���� ����
		virtual char*  get_table_name(uint32_t id);
	public:
		//�жϼ�¼�Ƿ���� ͨ�� ID 
		virtual int id_is_existed(uint32_t id, bool * existed);
		virtual int id_is_existed(uint32_t id, uint32_t key2, bool * existed);
		// table_name_pre : ������ǰ�沿�֣��磺 t_user_pet_00 --  t_user_pet_99, д�����t_user_pet 
		// id_name : ����id_is_existed������
		CtableRoute(mysql_interface * db, const char * db_name_pre,  
		 const char * table_name_pre,const char* id_name ,const char* key2_name="") ;


    //ʹ��userid Ϊ����

        //����int�ֶ�
        int set_int_value(userid_t userid ,const char * field_type , uint32_t  value);
        //�õ�int�ֶε�ֵ
        int get_int_value(userid_t userid ,const char * field_type ,  uint32_t * p_value);
        //����int�ֶ��е�ĳһλ, bitid  ��[1..32]
        int set_int_value_bit(uint32_t userid ,
                const char * field_type ,uint32_t bitid ,uint32_t  value);

        //�޸�int�ֶεĵ�ֵ
        // changevalue : �޸Ķ���
        // max_value ���ֵ
        // p_cur_value ���ص�ǰֵ 
        // p_real_change_value ����ʵ���޸Ķ��� 
        // is_change_to_max_min  ����������ֵ�������ֵ(��С��0)���Ƿ�����Ϊ���ֵ(��0)
        int change_int_value(userid_t userid ,const char * field_type , 
                int32_t changevalue, uint32_t max_value , uint32_t *p_cur_value=NULL,
                int32_t *p_real_change_value=NULL, bool is_change_to_max_min=false);




	//ʹ��userid ,����һ��key  Ϊ����, key �磺װ����е� attireid (װ��ID )	
		int set_int_value(userid_t userid ,uint32_t key2 ,const char * field_type , uint32_t  value);
		int get_int_value(userid_t userid,uint32_t key2 ,const char * field_type ,  uint32_t * p_value);
		int set_int_value_bit(uint32_t userid ,uint32_t key2, 
				const char * field_type ,uint32_t bitid ,uint32_t  value);


		int change_int_value(userid_t userid ,uint32_t key2 ,const char * field_type ,
			   	int32_t changevalue, uint32_t max_value , uint32_t *p_cur_value=NULL, 
				int32_t *p_real_change_value=NULL, bool is_change_to_max_min=false);
		virtual ~CtableRoute(void){} 

		int get_insert_sql_by_userid( userid_t userid, std::string & sql_str,
				const char * userid_field_name="userid" ,uint32_t obj_userid=0);
};

#endif   /* ----- #ifndef CTABLEROUTE_INCL  ----- */
