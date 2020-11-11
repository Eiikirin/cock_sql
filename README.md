# cock_sql

[![sampctl](https://img.shields.io/badge/sampctl-cock_sql-2f2f2f.svg?style=for-the-badge)](https://github.com/Se8870/cock_sql)

A forked MySQL and SQLite in Pawn originally by leHeix

## Installation

Simply install to your project:

```bash
sampctl package install Se8870/cock_sql
```

Include in your code and begin using the library:

```pawn
#include <cock_sql>
```

## Natives
```pawn
native cock_log(E_LOGLEVEL:loglevel = ERROR | WARNING);
native CockSQL:cock_connect(const host[], const user[], const password[], const database[], CockSQLOpt:option_id = CockSQLOpt:0);
native CockSQL:cock_connect_file(const file_name[] = "cocksql.ini");
native cock_close(CockSQL:handle = COCKSQL_DEFAULT_HANDLE);

native cock_unprocessed_queries(CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_global_options(E_COCK_GLOBAL_OPTION:type, value);

native cock_pquery(CockSQL:handle, const query[], const callback[] = "", const format[] = "", {Float, _}...);
native cock_tquery(CockSQL:handle, const query[], const callback[] = "", const format[] = "", {Float, _}...);
native Cockhe:cock_query(CockSQL:handle, const query[], bool:use_cache = true);	
native cock_tquery_file(CockSQL:handle, const file_path[], const callback[] = "", const format[] = "", {Float,_}:...);
native Cockhe:cock_query_file(CockSQL:handle, const file_path[], bool:use_cache = false);

native cock_errno(CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_error(const destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_escape_string(const source[], destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_format(CockSQL:handle, output[], max_len, const format[], {Float,_}:...);
native cock_set_charset(const charset[], CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_get_charset(destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE);
native cock_stat(destination[], max_len = sizeof(destination), CockSQL:handle = COCKSQL_DEFAULT_HANDLE);

native cockhe_get_row_count(&destination);
native cockhe_get_field_count(&destination);
native cockhe_get_result_count(&destination);
native cockhe_get_field_name(field_index, destination[], max_len = sizeof(destination));
native E_COCK_FIELD_TYPE:cockhe_get_field_type(field_index);
native cockhe_set_result(result_index);

native cockhe_get_value_index(row_idx, column_idx, destination[], max_len = sizeof(destination));
native cockhe_get_value_index_int(row_idx, column_idx, &destination);
native cockhe_get_value_index_float(row_idx, column_idx, &Float:destination);

native cockhe_is_value_index_null(row_idx, column_idx, &bool:destination);
native cockhe_get_value_name(row_idx, const column_name[], destination[], max_len = sizeof(destination));
native cockhe_get_value_name_int(row_idx, const column_name[], &destination);
native cockhe_get_value_name_float(row_idx, const column_name[], &Float:destination);

native cockhe_is_value_name_null(row_idx, const column_name[], &bool:destination);

native Cockhe:cockhe_save();
native cockhe_delete(Cockhe:cache_id);
native cockhe_set_active(Cockhe:cache_id);
native cockhe_unset_active();
native bool:cockhe_is_any_active();
native bool:cockhe_is_valid(Cockhe:cache_id);

native cockhe_affected_rows();
native cockhe_insert_id();
native cockhe_warning_count();

native cockhe_get_query_exec_time(E_COCK_EXECTIME_UNIT:unit = MICROSECONDS);
native cockhe_get_query_string(destination[], max_len = sizeof(destination));


native CockDB:cocklite_open(const name[]);
native cocklite_close(CockDB:db);
native cocklite_query(CockDB:db, const query[]);
native cocklite_free_result(CBResult:dbresult);
native cocklite_next_row(CockDBResult:dbresult);
native cocklite_num_rows(CockDBResult:dbresult);
native cocklite_num_fields(CockDBResult:dbresult);

native cocklite_get_field(CockDBResult:result, field, result[], maxlength = sizeof result);
native cocklite_get_field_int(CockDBResult:result, field = 0);
native cocklite_get_field_float(CockDBResult:result, field = 0);
native cocklite_get_field_assoc(CockDBResult:result, const field[], result[], maxlength = sizeof result);
native cocklite_get_field_assoc_int(CockDBResult:result, const field[]);
native cocklite_get_field_assoc_float(CockDBResult:result, const field[]);
```
