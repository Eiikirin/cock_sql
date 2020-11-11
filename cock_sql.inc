#if defined _inc_cock_sql
	#endinput
#endif
#define _inc_cock_sql

#include <a_mysql>

#if defined mysql_included
	#define CockSQL: MySQL:
	#define Cockhe: Cache:
	#define CockSQLOpt: MySQLOpt:
    #define E_COCK_GLOBAL_OPTION: E_MYSQL_GLOBAL_OPTION:
    #define E_COCK_EXECTIME_UNIT: E_MYSQL_EXECTIME_UNIT:
    #define E_COCK_FIELD_TYPE: E_MYSQL_FIELD_TYPE:

    #define COCKSQL_DEFAULT_HANDLE  MYSQL_DEFAULT_HANDLE
	#define COCKSQL_INVALID_HANDLE  MYSQL_INVALID_HANDLE    
	#define COCKSQL_INVALID_CACHE   MYSQL_INVALID_CACHE
	#define COCKSQL_INVALID_ORM     MYSQL_INVALID_ORM

    // Cock functions
    native cock_log(E_LOGLEVEL:loglevel = ERROR | WARNING) = mysql_log;
    native CockSQL:cock_connect(const host[], const user[], const password[], const database[], CockSQLOpt:option_id = CockSQLOpt:0) = mysql_connect;
	native CockSQL:cock_connect_file(const file_name[] = "cocksql.ini") = mysql_connect_file;
    native cock_close(CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_close;

    native cock_unprocessed_queries(CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_unprocessed_queries;
    native cock_global_options(E_COCK_GLOBAL_OPTION:type, value) = mysql_global_options;

	native cock_pquery(CockSQL:handle, const query[], const callback[] = "", const format[] = "", {Float, _}:...) = mysql_pquery;
    native cock_tquery(CockSQL:handle, const query[], const callback[] = "", const format[] = "", {Float, _}:...) = mysql_tquery;
    native Cockhe:cock_query(CockSQL:handle, const query[], bool:use_cache = true) = mysql_query;	
    native cock_tquery_file(CockSQL:handle, const file_path[], const callback[] = "", const format[] = "", {Float,_}:...) = mysql_tquery_file;
    native Cockhe:cock_query_file(CockSQL:handle, const file_path[], bool:use_cache = false) = mysql_query_file;

    native cock_errno(CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_errno;
    native cock_error(const destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_error;
    native cock_escape_string(const source[], destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_escape_string;
    native cock_format(CockSQL:handle, output[], max_len, const format[], {Float,_}:...) = mysql_format;
    native cock_set_charset(const charset[], CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_set_charset;
    native cock_get_charset(destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_get_charset;
    native cock_stat(destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE) = mysql_stat;

    // Cockhe functions
    native cockhe_get_row_count(&destination) = cache_get_row_count;
    native cockhe_get_field_count(&destination) = cache_get_field_count;
    native cockhe_get_result_count(&destination) = cache_get_result_count;
    native cockhe_get_field_name(field_index, destination[], max_len = sizeof(destination)) = cache_get_field_name;
    native E_COCK_FIELD_TYPE:cockhe_get_field_type(field_index) = cache_get_field_type;
    native cockhe_set_result(result_index) = cache_set_result;

    stock cockhe_num_rows()
    {
        new row_count;
        cockhe_get_row_count(row_count);
        return row_count;
    }
    stock cockhe_num_fields()
    {
        new field_count;
        cockhe_get_field_count(field_count);
        return field_count;
    }
    stock cockhe_num_results()
    {
        new result_count;
        cockhe_get_result_count(result_count);
        return result_count;
    }

    #define cockhe_get_value(%1)        cache_get_value(%1)
    #define cockhe_get_value_int(%1)    cache_get_value_int(%1)
    #define cockhe_get_value_float(%1)  cache_get_value_float(%1)
    #define cockhe_get_value_bool(%1)   cache_get_value_bool(%1)
    #define cockhe_is_value_null(%1)    cache_is_value_null(%1)

    native cockhe_get_value_index(row_idx, column_idx, destination[], max_len = sizeof(destination)) = cache_get_value_index;
    native cockhe_get_value_index_int(row_idx, column_idx, &destination) = cache_get_value_index_int;
    native cockhe_get_value_index_float(row_idx, column_idx, &Float:destination) = cache_get_value_index_float;

    stock cockhe_get_value_index_bool(row_idx, column_idx, &bool:destination)
    {
        return cockhe_get_value_index_int(row_idx, column_idx, _:destination);
    }

    native cockhe_is_value_index_null(row_idx, column_idx, &bool:destination) = cache_is_value_index_null;
    native cockhe_get_value_name(row_idx, const column_name[], destination[], max_len = sizeof(destination)) = cache_get_value_name;
    native cockhe_get_value_name_int(row_idx, const column_name[], &destination) = cache_get_value_name_int;
    native cockhe_get_value_name_float(row_idx, const column_name[], &Float:destination) = cache_get_value_name_float;

    stock cockhe_get_value_name_bool(row_idx, const column_name[], &bool:destination)
    {
        return cockhe_get_value_name_int(row_idx, column_name, _:destination);
    }
    native cockhe_is_value_name_null(row_idx, const column_name[], &bool:destination) = cache_is_value_name_null;

    native Cockhe:cockhe_save() = cache_save;
    native cockhe_delete(Cockhe:cache_id) = cache_delete;
    native cockhe_set_active(Cockhe:cache_id) = cache_set_active;
    native cockhe_unset_active() = cache_unset_active;
    native bool:cockhe_is_any_active() = cache_is_any_active;
    native bool:cockhe_is_valid(Cockhe:cache_id) = cache_is_valid;

    native cockhe_affected_rows() = cache_affected_rows;
    native cockhe_insert_id() = cache_insert_id;
    native cockhe_warning_count() = cache_warning_count;

    native cockhe_get_query_exec_time(E_COCK_EXECTIME_UNIT:unit = MICROSECONDS) = cache_get_query_exec_time;
    native cockhe_get_query_string(destination[], max_len = sizeof(destination)) = cache_get_query_string;
#endif

#define CockDB: DB:
#define CockDBResult: DBResult:

native CockDB:cocklite_open(const name[]) = db_open;
native cocklite_close(CockDB:db) = db_close;
native cocklite_query(CockDB:db, const query[]) = db_query;
native cocklite_free_result(CockBResult:dbresult) = db_free_result;
native cocklite_next_row(CockDBResult:dbresult) = db_next_row;
native cocklite_num_rows(CockDBResult:dbresult) = db_num_rows;
native cocklite_num_fields(CockDBResult:dbresult) = db_num_fields;

native cocklite_get_field(CockDBResult:dbresult, field, result[], maxlength = sizeof result) = db_get_field;
native cocklite_get_field_int(CockDBResult:dbresult, field = 0) = db_get_field_int;
native cocklite_get_field_float(CockDBResult:dbresult, field = 0) = db_get_field_float;

stock bool:cocklite_get_field_bool(CockDBResult:dbresult, field = 0) 
{
    return cocklite_get_field_int(dbresult, field);
}

native cocklite_get_field_assoc(CockDBResult:dbresult, const field[], result[], maxlength = sizeof result) = db_get_field_assoc;
native cocklite_get_field_assoc_int(CockDBResult:dbresult, const field[]) = db_get_field_assoc_int;
native cocklite_get_field_assoc_float(CockDBResult:dbresult, const field[]) = db_get_field_assoc_float;

stock bool:cocklite_get_field_assoc_bool(CockDBResult:dbresult, const field[]) 
{
    return cocklite_get_field_assoc_int(dbresult, field);
}
