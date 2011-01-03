#line 214 "/usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stddef.h"
typedef unsigned long size_t;
#line 144 "/usr/include/bits/types.h"
typedef long __off_t;
#line 145 "/usr/include/bits/types.h"
typedef long __off64_t;
#line 197 "/usr/include/sys/types.h"
typedef int int32_t;
#line 46 "/usr/include/stdio.h"
struct _IO_FILE;
#line 46
struct _IO_FILE;
#line 46 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 177 "/usr/include/libio.h"
typedef void _IO_lock_t;
#line 183 "/usr/include/libio.h"
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
#line 268 "/usr/include/libio.h"
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
#line 106 "/usr/include/getopt.h"
struct option {
   char const   *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
#line 49 "/usr/include/stdint.h"
typedef unsigned char uint8_t;
#line 50 "/usr/include/stdint.h"
typedef unsigned short uint16_t;
#line 52 "/usr/include/stdint.h"
typedef unsigned int uint32_t;
#line 24 "json.h"
enum __anonenum_json_type_26 {
    JSON_NONE = 0,
    JSON_ARRAY_BEGIN = 1,
    JSON_OBJECT_BEGIN = 2,
    JSON_ARRAY_END = 3,
    JSON_OBJECT_END = 4,
    JSON_INT = 5,
    JSON_FLOAT = 6,
    JSON_STRING = 7,
    JSON_KEY = 8,
    JSON_TRUE = 9,
    JSON_FALSE = 10,
    JSON_NULL = 11
} ;
#line 24 "json.h"
typedef enum __anonenum_json_type_26 json_type;
#line 75 "json.h"
struct __anonstruct_json_config_28 {
   uint32_t buffer_initial_size ;
   uint32_t max_nesting ;
   uint32_t max_data ;
   int allow_c_comments ;
   int allow_yaml_comments ;
   void *(*user_calloc)(size_t nmemb , size_t size ) ;
   void *(*user_realloc)(void *ptr , size_t size ) ;
};
#line 75 "json.h"
typedef struct __anonstruct_json_config_28 json_config;
#line 85 "json.h"
struct json_parser {
   json_config config ;
   int (*callback)(void *userdata , int type , char const   *data ,
                   uint32_t length ) ;
   void *userdata ;
   uint8_t state ;
   uint8_t save_state ;
   uint8_t expecting_key ;
   uint16_t unicode_multi ;
   json_type type ;
   uint8_t *stack ;
   uint32_t stack_offset ;
   uint32_t stack_size ;
   char *buffer ;
   uint32_t buffer_size ;
   uint32_t buffer_offset ;
};
#line 85 "json.h"
typedef struct json_parser json_parser;
#line 110 "json.h"
struct json_printer {
   int (*callback)(void *userdata , char const   *s , uint32_t length ) ;
   void *userdata ;
   char *indentstr ;
   int indentlevel ;
   int afterkey ;
   int enter_object ;
   int first ;
};
#line 110 "json.h"
typedef struct json_printer json_printer;
#line 176 "json.h"
struct stack_elem {
   void *val ;
   char *key ;
   uint32_t key_length ;
};
#line 176 "json.h"
struct json_parser_dom {
   struct stack_elem *stack ;
   uint32_t stack_size ;
   uint32_t stack_offset ;
   void *(*user_calloc)(size_t nmemb , size_t size ) ;
   void *(*user_realloc)(void *ptr , size_t size ) ;
   void *root_structure ;
   void *(*create_structure)(int  , int  ) ;
   void *(*create_data)(int  , char const   * , uint32_t  ) ;
   int (*append)(void * , char * , uint32_t  , void * ) ;
};
#line 176 "json.h"
typedef struct json_parser_dom json_parser_dom;
#line 222 "jsonlint.c"
struct json_val;
#line 222
struct json_val;
#line 222 "jsonlint.c"
struct json_val_elem {
   char *key ;
   uint32_t key_length ;
   struct json_val *val ;
};
#line 228 "jsonlint.c"
union __anonunion_u_29 {
   char *data ;
   struct json_val **array ;
   struct json_val_elem **object ;
};
#line 228 "jsonlint.c"
struct json_val {
   int type ;
   int length ;
   union __anonunion_u_29 u ;
};
#line 228 "jsonlint.c"
typedef struct json_val json_val_t;
#line 43 "/usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
#line 105 "/usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdarg.h"
typedef __gnuc_va_list va_list;
#line 544 "json.c"
struct action_descr {
   int (*call)(json_parser *parser ) ;
   uint8_t type ;
   uint8_t state ;
   uint8_t dobuffer ;
};
/* compiler builtin: 
   void __builtin_varargs_start(__builtin_va_list  ) ;  */
/* compiler builtin: 
   int __builtin_strcmp(char const   * , char const   * ) ;  */
/* compiler builtin: 
   void *__builtin___memmove_chk(void * , void const   * , unsigned long  ,
                                 unsigned long  ) ;  */
/* compiler builtin: 
   char *__builtin_strpbrk(char const   * , char const   * ) ;  */
/* compiler builtin: 
   void *__builtin_memcpy(void * , void const   * , unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_exp(double  ) ;  */
/* compiler builtin: 
   long double __builtin_nanl(char const   * ) ;  */
/* compiler builtin: 
   double __builtin_cos(double  ) ;  */
/* compiler builtin: 
   char *__builtin_strchr(char * , int  ) ;  */
/* compiler builtin: 
   float __builtin_atan2f(float  , float  ) ;  */
/* compiler builtin: 
   void *__builtin___memcpy_chk(void * , void const   * , unsigned long  ,
                                unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_asin(double  ) ;  */
/* compiler builtin: 
   int __builtin_ctz(unsigned int  ) ;  */
/* compiler builtin: 
   char *__builtin_stpcpy(char * , char const   * ) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_unpckhps(float __attribute__((____vector_size____(16)))   ,
                                                                           float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   double __builtin_nans(char const   * ) ;  */
/* compiler builtin: 
   long double __builtin_atan2l(long double  , long double  ) ;  */
/* compiler builtin: 
   float __builtin_logf(float  ) ;  */
/* compiler builtin: 
   int __builtin___fprintf_chk(void * , int  , char const   *  , ...) ;  */
/* compiler builtin: 
   int __builtin___vsprintf_chk(char * , int  , unsigned long  ,
                                char const   * , __builtin_va_list  ) ;  */
/* compiler builtin: 
   char *__builtin___strncpy_chk(char * , char const   * , unsigned long  ,
                                 unsigned long  ) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_subps(float __attribute__((____vector_size____(16)))   ,
                                                                        float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   float __builtin_log10f(float  ) ;  */
/* compiler builtin: 
   double __builtin_atan(double  ) ;  */
/* compiler builtin: 
   void *__builtin_alloca(unsigned long  ) ;  */
/* compiler builtin: 
   void __builtin_va_end(__builtin_va_list  ) ;  */
/* compiler builtin: 
   int __builtin_strncmp(char const   * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_sin(double  ) ;  */
/* compiler builtin: 
   long double __builtin_logl(long double  ) ;  */
/* compiler builtin: 
   float __builtin_coshf(float  ) ;  */
/* compiler builtin: 
   void *__builtin___mempcpy_chk(void * , void const   * , unsigned long  ,
                                 unsigned long  ) ;  */
/* compiler builtin: 
   char *__builtin___strcat_chk(char * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   float __builtin_nansf(char const   * ) ;  */
/* compiler builtin: 
   void *__builtin_memset(void * , int  , int  ) ;  */
/* compiler builtin: 
   void __builtin_va_copy(__builtin_va_list  , __builtin_va_list  ) ;  */
/* compiler builtin: 
   float __builtin_sinhf(float  ) ;  */
/* compiler builtin: 
   long double __builtin_log10l(long double  ) ;  */
/* compiler builtin: 
   long double __builtin_coshl(long double  ) ;  */
/* compiler builtin: 
   unsigned long __builtin_strlen(char const   * ) ;  */
/* compiler builtin: 
   int __builtin_ffs(unsigned int  ) ;  */
/* compiler builtin: 
   float __builtin_asinf(float  ) ;  */
/* compiler builtin: 
   long double __builtin_nansl(char const   * ) ;  */
/* compiler builtin: 
   double __builtin_frexp(double  , int * ) ;  */
/* compiler builtin: 
   double __builtin_tan(double  ) ;  */
/* compiler builtin: 
   long double __builtin_sinhl(long double  ) ;  */
/* compiler builtin: 
   float __builtin_frexpf(float  , int * ) ;  */
/* compiler builtin: 
   long double __builtin_asinl(long double  ) ;  */
/* compiler builtin: 
   void *__builtin_frame_address(unsigned int  ) ;  */
/* compiler builtin: 
   double __builtin_floor(double  ) ;  */
/* compiler builtin: 
   float __builtin_tanhf(float  ) ;  */
/* compiler builtin: 
   int __builtin_parityl(unsigned long  ) ;  */
/* compiler builtin: 
   int __builtin_clzl(unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_powi(double  , int  ) ;  */
/* compiler builtin: 
   long double __builtin_frexpl(long double  , int * ) ;  */
/* compiler builtin: 
   float __builtin_atanf(float  ) ;  */
/* compiler builtin: 
   float __builtin_huge_valf(void) ;  */
/* compiler builtin: 
   float __builtin_sqrtf(float  ) ;  */
/* compiler builtin: 
   float __builtin_fmodf(float  ) ;  */
/* compiler builtin: 
   unsigned long __builtin_object_size(void * , int  ) ;  */
/* compiler builtin: 
   void __builtin_va_arg(__builtin_va_list  , unsigned long  , void * ) ;  */
/* compiler builtin: 
   void __builtin_stdarg_start(__builtin_va_list  ) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_mulps(float __attribute__((____vector_size____(16)))   ,
                                                                        float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   long double __builtin_tanhl(long double  ) ;  */
/* compiler builtin: 
   double __builtin_nan(char const   * ) ;  */
/* compiler builtin: 
   void __builtin_return(void const   * ) ;  */
/* compiler builtin: 
   long double __builtin_atanl(long double  ) ;  */
/* compiler builtin: 
   long double __builtin_huge_vall(void) ;  */
/* compiler builtin: 
   float __builtin_inff(void) ;  */
/* compiler builtin: 
   long double __builtin_sqrtl(long double  ) ;  */
/* compiler builtin: 
   long double __builtin_fmodl(long double  ) ;  */
/* compiler builtin: 
   int __builtin___printf_chk(int  , char const   *  , ...) ;  */
/* compiler builtin: 
   float __builtin_floorf(float  ) ;  */
/* compiler builtin: 
   float __builtin_fabsf(float  ) ;  */
/* compiler builtin: 
   int __builtin_popcountll(unsigned long long  ) ;  */
/* compiler builtin: 
   int __builtin___sprintf_chk(char * , int  , unsigned long  , char const   * 
                               , ...) ;  */
/* compiler builtin: 
   int __builtin___vprintf_chk(int  , char const   * , __builtin_va_list  ) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_maxps(float __attribute__((____vector_size____(16)))   ,
                                                                        float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   int __builtin___snprintf_chk(char * , unsigned long  , int  ,
                                unsigned long  , char const   *  , ...) ;  */
/* compiler builtin: 
   long double __builtin_infl(void) ;  */
/* compiler builtin: 
   void *__builtin_mempcpy(void * , void const   * , unsigned long  ) ;  */
/* compiler builtin: 
   long double __builtin_floorl(long double  ) ;  */
/* compiler builtin: 
   int __builtin_ctzl(unsigned long  ) ;  */
/* compiler builtin: 
   long double __builtin_fabsl(long double  ) ;  */
/* compiler builtin: 
   int __builtin_clz(unsigned int  ) ;  */
/* compiler builtin: 
   double __builtin_fabs(double  ) ;  */
/* compiler builtin: 
   int __builtin_popcount(unsigned int  ) ;  */
/* compiler builtin: 
   void __builtin_bcopy(void const   * , void * , unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_ceil(double  ) ;  */
/* compiler builtin: 
   double __builtin_ldexp(double  , int  ) ;  */
/* compiler builtin: 
   float __builtin_sinf(float  ) ;  */
/* compiler builtin: 
   float __builtin_acosf(float  ) ;  */
/* compiler builtin: 
   int __builtin___vsnprintf_chk(char * , unsigned long  , int  ,
                                 unsigned long  , char const   * ,
                                 __builtin_va_list  ) ;  */
/* compiler builtin: 
   double __builtin_sinh(double  ) ;  */
/* compiler builtin: 
   int __builtin_ffsll(unsigned long long  ) ;  */
/* compiler builtin: 
   char *__builtin___strcpy_chk(char * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_inf(void) ;  */
/* compiler builtin: 
   void __builtin_prefetch(void const   *  , ...) ;  */
/* compiler builtin: 
   long double __builtin_sinl(long double  ) ;  */
/* compiler builtin: 
   long double __builtin_acosl(long double  ) ;  */
/* compiler builtin: 
   double __builtin_sqrt(double  ) ;  */
/* compiler builtin: 
   double __builtin_fmod(double  ) ;  */
/* compiler builtin: 
   char *__builtin_strcpy(char * , char const   * ) ;  */
/* compiler builtin: 
   float __builtin_ceilf(float  ) ;  */
/* compiler builtin: 
   void *__builtin_return_address(unsigned int  ) ;  */
/* compiler builtin: 
   char *__builtin___stpcpy_chk(char * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   float __builtin_tanf(float  ) ;  */
/* compiler builtin: 
   int __builtin_parityll(unsigned long long  ) ;  */
/* compiler builtin: 
   float __builtin_ldexpf(float  , int  ) ;  */
/* compiler builtin: 
   int __builtin_types_compatible_p(unsigned long  , unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_log10(double  ) ;  */
/* compiler builtin: 
   float __builtin_expf(float  ) ;  */
/* compiler builtin: 
   int __builtin_clzll(unsigned long long  ) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_unpcklps(float __attribute__((____vector_size____(16)))   ,
                                                                           float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   double __builtin_tanh(double  ) ;  */
/* compiler builtin: 
   int __builtin_constant_p(int  ) ;  */
/* compiler builtin: 
   long double __builtin_ceill(long double  ) ;  */
/* compiler builtin: 
   int __builtin_va_arg_pack_len(void) ;  */
/* compiler builtin: 
   void *__builtin_apply(void (*)() , void * , unsigned long  ) ;  */
/* compiler builtin: 
   long double __builtin_tanl(long double  ) ;  */
/* compiler builtin: 
   double __builtin_log(double  ) ;  */
/* compiler builtin: 
   long double __builtin_ldexpl(long double  , int  ) ;  */
/* compiler builtin: 
   int __builtin_popcountl(unsigned long  ) ;  */
/* compiler builtin: 
   long double __builtin_expl(long double  ) ;  */
/* compiler builtin: 
   void *__builtin___memset_chk(void * , int  , unsigned long  , unsigned long  ) ;  */
/* compiler builtin: 
   char *__builtin___strncat_chk(char * , char const   * , unsigned long  ,
                                 unsigned long  ) ;  */
/* compiler builtin: 
   double __builtin_huge_val(void) ;  */
/* compiler builtin: 
   __builtin_va_list __builtin_next_arg(void) ;  */
/* compiler builtin: 
   void *__builtin_apply_args(void) ;  */
/* compiler builtin: 
   float __builtin_powif(float  , int  ) ;  */
/* compiler builtin: 
   int __builtin___vfprintf_chk(void * , int  , char const   * ,
                                __builtin_va_list  ) ;  */
/* compiler builtin: 
   float __builtin_modff(float  , float * ) ;  */
/* compiler builtin: 
   double __builtin_atan2(double  , double  ) ;  */
/* compiler builtin: 
   char *__builtin_strncpy(char * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   long double __builtin_powil(long double  , int  ) ;  */
/* compiler builtin: 
   float __builtin_cosf(float  ) ;  */
/* compiler builtin: 
   void __builtin_bzero(void * , unsigned long  ) ;  */
/* compiler builtin: 
   unsigned long __builtin_strspn(char const   * , char const   * ) ;  */
/* compiler builtin: 
   long double __builtin_modfl(long double  , long double * ) ;  */
/* compiler builtin: 
   int __builtin_parity(unsigned int  ) ;  */
/* compiler builtin: 
   double __builtin_cosh(double  ) ;  */
/* compiler builtin: 
   char *__builtin_strncat(char * , char const   * , unsigned long  ) ;  */
/* compiler builtin: 
   long __builtin_expect(long  , long  ) ;  */
/* compiler builtin: 
   double __builtin_acos(double  ) ;  */
/* compiler builtin: 
   int __builtin_va_arg_pack(void) ;  */
/* compiler builtin: 
   float __attribute__((____vector_size____(16)))  __builtin_ia32_addps(float __attribute__((____vector_size____(16)))   ,
                                                                        float __attribute__((____vector_size____(16)))   ) ;  */
/* compiler builtin: 
   long double __builtin_cosl(long double  ) ;  */
/* compiler builtin: 
   void __builtin_va_start(__builtin_va_list  ) ;  */
/* compiler builtin: 
   int __builtin_ctzll(unsigned long long  ) ;  */
/* compiler builtin: 
   unsigned long __builtin_strcspn(char const   * , char const   * ) ;  */
/* compiler builtin: 
   int __builtin_ffsl(unsigned long  ) ;  */
/* compiler builtin: 
   float __builtin_nanf(char const   * ) ;  */
#line 1 "jsonlint.o"
/* #pragma merger(0,"/tmp/cil-7zlYBOB2.i","-Wall,-Os,-fPIC") */
#line 148 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) int atoi(char const   *__nptr )  __attribute__((__pure__,
__nonnull__(1))) ;
#line 589
extern  __attribute__((__nothrow__)) void *malloc(size_t __size )  __attribute__((__malloc__)) ;
#line 591
extern  __attribute__((__nothrow__)) void *calloc(size_t __nmemb ,
                                                  size_t __size )  __attribute__((__malloc__)) ;
#line 600
extern  __attribute__((__nothrow__)) void *realloc(void *__ptr , size_t __size )  __attribute__((__warn_unused_result__,
__malloc__)) ;
#line 603
extern  __attribute__((__nothrow__)) void free(void *__ptr ) ;
#line 646
extern  __attribute__((__nothrow__, __noreturn__)) void exit(int __status ) ;
#line 142 "/usr/include/stdio.h"
extern struct _IO_FILE *stdin ;
#line 143
extern struct _IO_FILE *stdout ;
#line 144
extern struct _IO_FILE *stderr ;
#line 213
extern int fclose(FILE *__stream ) ;
#line 248
extern FILE *fopen(char const   * __restrict  __filename ,
                   char const   * __restrict  __modes ) ;
#line 327
extern int fprintf(FILE * __restrict  __stream ,
                   char const   * __restrict  __format  , ...) ;
#line 333
extern int printf(char const   * __restrict  __format  , ...) ;
#line 610
extern size_t fread(void * __restrict  __ptr , size_t __size , size_t __n ,
                    FILE * __restrict  __stream ) ;
#line 616
extern size_t fwrite(void const   * __restrict  __ptr , size_t __size ,
                     size_t __n , FILE * __restrict  __s ) ;
#line 38 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) void *memcpy(void * __restrict  __dest ,
                                                  void const   * __restrict  __src ,
                                                  size_t __n )  __attribute__((__nonnull__(1,2))) ;
#line 59
extern  __attribute__((__nothrow__)) void *memset(void *__s , int __c ,
                                                  size_t __n )  __attribute__((__nonnull__(1))) ;
#line 99
extern  __attribute__((__nothrow__)) int strcmp(char const   *__s1 ,
                                                char const   *__s2 )  __attribute__((__pure__,
__nonnull__(1,2))) ;
#line 130
extern  __attribute__((__nothrow__)) char *strdup(char const   *__s )  __attribute__((__nonnull__(1),
__malloc__)) ;
#line 256
extern  __attribute__((__nothrow__)) char *strerror(int __errnum ) ;
#line 59 "/usr/include/getopt.h"
extern char *optarg ;
#line 73
extern int optind ;
#line 159
extern  __attribute__((__nothrow__)) int getopt_long(int ___argc ,
                                                     char * const  *___argv ,
                                                     char const   *__shortopts ,
                                                     struct option  const  *__longopts ,
                                                     int *__longind ) ;
#line 43 "/usr/include/bits/errno.h"
extern  __attribute__((__nothrow__)) int *__errno_location(void)  __attribute__((__const__)) ;
#line 124 "json.h"
int json_parser_init(json_parser *parser , json_config *config ,
                     int (*callback)(void *userdata , int type ,
                                     char const   *data , uint32_t length ) ,
                     void *userdata ) ;
#line 128
int json_parser_free(json_parser *parser ) ;
#line 134
int json_parser_string(json_parser *parser , char const   *s , uint32_t length ,
                       uint32_t *processed ) ;
#line 142
int json_parser_is_done(json_parser *parser ) ;
#line 145
int json_print_init(json_printer *printer ,
                    int (*callback)(void *userdata , char const   *s ,
                                    uint32_t length ) , void *userdata ) ;
#line 149
int json_print_free(json_printer *printer ) ;
#line 152
int json_print_pretty(json_printer *printer , int type , char const   *data ,
                      uint32_t length ) ;
#line 197
int json_parser_dom_init(json_parser_dom *dom ,
                         void *(*create_structure)(int  , int  ) ,
                         void *(*create_data)(int  , char const   * , uint32_t  ) ,
                         int (*append)(void * , char * , uint32_t  , void * ) ) ;
#line 205
int json_parser_dom_callback(void *userdata , int type , char const   *data ,
                             uint32_t length ) ;
#line 24 "jsonlint.c"
char *indent_string  =    (char *)((void *)0);
#line 26 "jsonlint.c"
char *string_of_errors[13]  = 
#line 26
  {      (char *)0,      (char *)"out of memory",      (char *)"bad character",      (char *)"stack empty", 
        (char *)"pop unexpected mode",      (char *)"nesting limit",      (char *)"data limit",      (char *)"comment not allowed by config", 
        (char *)"unexpected char",      (char *)"missing unicode low surrogate",      (char *)"unexpected unicode low surrogate",      (char *)"error comma out of structure", 
        (char *)"error in a callback"};
#line 42 "jsonlint.c"
static int printchannel(void *userdata , char const   *data , uint32_t length ) 
{ FILE *channel ;
  int ret ;
  size_t tmp ;

  {
#line 44
  channel = (FILE *)userdata;
#line 47
  tmp = fwrite((void const   */* __restrict  */)data, (unsigned long )length,
               1UL, (FILE */* __restrict  */)channel);
#line 47
  ret = (int )tmp;
#line 48
  return (0);
}
}
#line 51 "jsonlint.c"
static int prettyprint(void *userdata , int type , char const   *data ,
                       uint32_t length ) 
{ json_printer *printer ;
  int tmp ;

  {
#line 53
  printer = (json_printer *)userdata;
#line 55
  tmp = json_print_pretty(printer, type, data, length);
#line 55
  return (tmp);
}
}
#line 58 "jsonlint.c"
FILE *open_filename(char const   *filename , char const   *opt , int is_input ) 
{ FILE *input ;
  int *tmp ;
  char *tmp___0 ;
  int tmp___1 ;

  {
#line 61
  tmp___1 = strcmp(filename, "-");
#line 61
  if (tmp___1 == 0) {
#line 62
    if (is_input) {
#line 62
      input = stdin;
    } else {
#line 62
      input = stdout;
    }
  } else {
#line 64
    input = fopen((char const   */* __restrict  */)filename,
                  (char const   */* __restrict  */)opt);
#line 65
    if (! input) {
#line 66
      tmp = __errno_location();
#line 66
      tmp___0 = strerror(*tmp);
#line 66
      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"error: cannot open %s: %s",
              filename, tmp___0);
#line 67
      return ((FILE *)((void *)0));
    } else {

    }
  }
#line 70
  return (input);
}
}
#line 73 "jsonlint.c"
void close_filename(char const   *filename , FILE *file ) 
{ int tmp ;

  {
#line 75
  tmp = strcmp(filename, "-");
#line 75
  if (tmp != 0) {
#line 76
    fclose(file);
  } else {

  }
#line 77
  return;
}
}
#line 79 "jsonlint.c"
int process_file(json_parser *parser , FILE *input , int *retlines ,
                 int *retcols ) 
{ char buffer[4096] ;
  int ret ;
  int32_t read ;
  int lines ;
  int col ;
  int i ;
  uint32_t processed ;
  size_t tmp ;

  {
#line 82
  ret = 0;
#line 86
  lines = 1;
#line 87
  col = 0;
#line 88
  while (1) {
#line 90
    tmp = fread((void */* __restrict  */)(buffer), 1UL, 4096UL,
                (FILE */* __restrict  */)input);
#line 90
    read = (int )tmp;
#line 91
    if (read <= 0) {
#line 92
      break;
    } else {

    }
#line 93
    ret = json_parser_string(parser, (char const   *)(buffer),
                             (unsigned int )read, & processed);
#line 94
    i = 0;
#line 94
    while ((unsigned int )i < processed) {
#line 95
      if ((int )buffer[i] == 10) {
#line 95
        col = 0;
#line 95
        lines ++;
      } else {
#line 95
        col ++;
      }
#line 94
      i ++;
    }
#line 97
    if (ret) {
#line 98
      break;
    } else {

    }
  }
#line 100
  if (retlines) {
#line 100
    *retlines = lines;
  } else {

  }
#line 101
  if (retcols) {
#line 101
    *retcols = col;
  } else {

  }
#line 102
  return (ret);
}
}
#line 105 "jsonlint.c"
static int do_verify(json_config *config , char const   *filename ) 
{ FILE *input ;
  json_parser parser ;
  int ret ;

  {
#line 111
  input = open_filename(filename, "r", 1);
#line 112
  if (! input) {
#line 113
    return (2);
  } else {

  }
#line 116
  ret = json_parser_init(& parser, config,
                         (int (*)(void *userdata , int type ,
                                  char const   *data ,
                                  uint32_t length ))((void *)0), (void *)0);
#line 117
  if (ret) {
#line 118
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing parser failed (code=%d): %s\n",
            ret, string_of_errors[ret]);
#line 119
    return (ret);
  } else {

  }
#line 122
  ret = process_file(& parser, input, (int *)((void *)0), (int *)((void *)0));
#line 123
  if (ret) {
#line 124
    return (1);
  } else {

  }
#line 126
  ret = json_parser_is_done(& parser);
#line 127
  if (! ret) {
#line 128
    return (1);
  } else {

  }
#line 130
  close_filename(filename, input);
#line 131
  return (0);
}
}
#line 134 "jsonlint.c"
static int do_parse(json_config *config , char const   *filename ) 
{ FILE *input ;
  json_parser parser ;
  int ret ;
  int col ;
  int lines ;

  {
#line 141
  input = open_filename(filename, "r", 1);
#line 142
  if (! input) {
#line 143
    return (2);
  } else {

  }
#line 146
  ret = json_parser_init(& parser, config,
                         (int (*)(void *userdata , int type ,
                                  char const   *data ,
                                  uint32_t length ))((void *)0), (void *)0);
#line 147
  if (ret) {
#line 148
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing parser failed (code=%d): %s\n",
            ret, string_of_errors[ret]);
#line 149
    return (ret);
  } else {

  }
#line 152
  ret = process_file(& parser, input, & lines, & col);
#line 153
  if (ret) {
#line 154
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"line %d, col %d: [code=%d] %s\n",
            lines, col, ret, string_of_errors[ret]);
#line 156
    return (1);
  } else {

  }
#line 159
  ret = json_parser_is_done(& parser);
#line 160
  if (! ret) {
#line 161
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"syntax error\n");
#line 162
    return (1);
  } else {

  }
#line 165
  close_filename(filename, input);
#line 166
  return (0);
}
}
#line 169 "jsonlint.c"
static int do_format(json_config *config , char const   *filename ,
                     char const   *outputfile ) 
{ FILE *input ;
  FILE *output ;
  json_parser parser ;
  json_printer printer ;
  int ret ;
  int col ;
  int lines ;

  {
#line 177
  input = open_filename(filename, "r", 1);
#line 178
  if (! input) {
#line 179
    return (2);
  } else {

  }
#line 181
  output = open_filename(outputfile, "a+", 0);
#line 182
  if (! output) {
#line 183
    return (2);
  } else {

  }
#line 186
  ret = json_print_init(& printer, & printchannel, (void *)stdout);
#line 187
  if (ret) {
#line 188
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing printer failed: [code=%d] %s\n",
            ret, string_of_errors[ret]);
#line 189
    return (ret);
  } else {

  }
#line 191
  if (indent_string) {
#line 192
    printer.indentstr = indent_string;
  } else {

  }
#line 194
  ret = json_parser_init(& parser, config, & prettyprint, (void *)(& printer));
#line 195
  if (ret) {
#line 196
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing parser failed: [code=%d] %s\n",
            ret, string_of_errors[ret]);
#line 197
    return (ret);
  } else {

  }
#line 200
  ret = process_file(& parser, input, & lines, & col);
#line 201
  if (ret) {
#line 202
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"line %d, col %d: [code=%d] %s\n",
            lines, col, ret, string_of_errors[ret]);
#line 204
    return (1);
  } else {

  }
#line 207
  ret = json_parser_is_done(& parser);
#line 208
  if (! ret) {
#line 209
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"syntax error\n");
#line 210
    return (1);
  } else {

  }
#line 214
  json_parser_free(& parser);
#line 215
  json_print_free(& printer);
#line 216
  fwrite((void const   */* __restrict  */)"\n", 1UL, 1UL,
         (FILE */* __restrict  */)stdout);
#line 217
  close_filename(filename, input);
#line 218
  return (0);
}
}
#line 238 "jsonlint.c"
static void *tree_create_structure(int nesting , int is_object ) 
{ json_val_t *v ;
  void *tmp ;

  {
#line 240
  tmp = malloc(sizeof(json_val_t ));
#line 240
  v = (json_val_t *)tmp;
#line 241
  if (v) {
#line 244
    if (is_object) {
#line 245
      v->type = 2;
#line 246
      v->u.object = (struct json_val_elem **)((void *)0);
    } else {
#line 248
      v->type = 1;
#line 249
      v->u.array = (struct json_val **)((void *)0);
    }
#line 251
    v->length = 0;
  } else {

  }
#line 253
  return ((void *)v);
}
}
#line 256 "jsonlint.c"
static char *memalloc_copy_length(char const   *src , uint32_t n ) 
{ char *dest ;
  void *tmp ;

  {
#line 260
  tmp = calloc((unsigned long )(n + 1U), sizeof(char ));
#line 260
  dest = (char *)tmp;
#line 261
  if (dest) {
#line 262
    memcpy((void */* __restrict  */)dest, (void const   */* __restrict  */)src,
           (unsigned long )n);
  } else {

  }
#line 263
  return (dest);
}
}
#line 266 "jsonlint.c"
static void *tree_create_data(int type , char const   *data , uint32_t length ) 
{ json_val_t *v ;
  void *tmp ;

  {
#line 270
  tmp = malloc(sizeof(json_val_t ));
#line 270
  v = (json_val_t *)tmp;
#line 271
  if (v) {
#line 272
    v->type = type;
#line 273
    v->length = (int )length;
#line 274
    v->u.data = memalloc_copy_length(data, length);
#line 275
    if (! v->u.data) {
#line 276
      free((void *)v);
#line 277
      return ((void *)0);
    } else {

    }
  } else {

  }
#line 280
  return ((void *)v);
}
}
#line 283 "jsonlint.c"
static int tree_append(void *structure , char *key , uint32_t key_length ,
                       void *obj ) 
{ json_val_t *parent ;
  struct json_val_elem *objelem ;
  void *tmp ;
  uint32_t newsize ;
  void *newptr ;
  void *tmp___0 ;
  int tmp___1 ;
  void *tmp___2 ;
  uint32_t newsize___0 ;
  void *newptr___0 ;
  int tmp___3 ;

  {
#line 285
  parent = (json_val_t *)structure;
#line 286
  if (key) {
#line 289
    if (parent->length == 0) {
#line 290
      tmp = calloc(2UL, sizeof(json_val_t *));
#line 290
      parent->u.object = (struct json_val_elem **)tmp;
#line 291
      if (! parent->u.object) {
#line 292
        return (1);
      } else {

      }
    } else {
#line 294
      newsize = (unsigned int )((parent->length + 1) + 1);
#line 297
      newptr = realloc((void *)parent->u.object,
                       (unsigned long )newsize * sizeof(json_val_t *));
#line 298
      if (! newptr) {
#line 299
        return (-1);
      } else {

      }
#line 300
      parent->u.object = (struct json_val_elem **)newptr;
    }
#line 303
    tmp___0 = malloc(sizeof(struct json_val_elem ));
#line 303
    objelem = (struct json_val_elem *)tmp___0;
#line 304
    if (! objelem) {
#line 305
      return (-1);
    } else {

    }
#line 307
    objelem->key = memalloc_copy_length((char const   *)key, key_length);
#line 308
    objelem->key_length = key_length;
#line 309
    objelem->val = (struct json_val *)obj;
#line 310
    tmp___1 = parent->length;
#line 310
    (parent->length) ++;
#line 310
    *(parent->u.object + tmp___1) = objelem;
#line 311
    *(parent->u.object + parent->length) = (struct json_val_elem *)((void *)0);
  } else {
#line 313
    if (parent->length == 0) {
#line 314
      tmp___2 = calloc(2UL, sizeof(json_val_t *));
#line 314
      parent->u.array = (struct json_val **)tmp___2;
#line 315
      if (! parent->u.array) {
#line 316
        return (1);
      } else {

      }
    } else {
#line 318
      newsize___0 = (unsigned int )((parent->length + 1) + 1);
#line 321
      newptr___0 = realloc((void *)parent->u.object,
                           (unsigned long )newsize___0 * sizeof(json_val_t *));
#line 322
      if (! newptr___0) {
#line 323
        return (-1);
      } else {

      }
#line 324
      parent->u.array = (struct json_val **)newptr___0;
    }
#line 326
    tmp___3 = parent->length;
#line 326
    (parent->length) ++;
#line 326
    *(parent->u.array + tmp___3) = (struct json_val *)obj;
#line 327
    *(parent->u.array + parent->length) = (struct json_val *)((void *)0);
  }
#line 329
  return (0);
}
}
#line 332 "jsonlint.c"
static int do_tree(json_config *config , char const   *filename ,
                   json_val_t **root_structure ) 
{ FILE *input ;
  json_parser parser ;
  json_parser_dom dom ;
  int ret ;
  int col ;
  int lines ;

  {
#line 340
  input = open_filename(filename, "r", 1);
#line 341
  if (! input) {
#line 342
    return (2);
  } else {

  }
#line 344
  ret = json_parser_dom_init(& dom, & tree_create_structure, & tree_create_data,
                             & tree_append);
#line 345
  if (ret) {
#line 346
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing helper failed: [code=%d] %s\n",
            ret, string_of_errors[ret]);
#line 347
    return (ret);
  } else {

  }
#line 350
  ret = json_parser_init(& parser, config, & json_parser_dom_callback,
                         (void *)(& dom));
#line 351
  if (ret) {
#line 352
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: initializing parser failed: [code=%d] %s\n",
            ret, string_of_errors[ret]);
#line 353
    return (ret);
  } else {

  }
#line 356
  ret = process_file(& parser, input, & lines, & col);
#line 357
  if (ret) {
#line 358
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"line %d, col %d: [code=%d] %s\n",
            lines, col, ret, string_of_errors[ret]);
#line 361
    return (1);
  } else {

  }
#line 364
  ret = json_parser_is_done(& parser);
#line 365
  if (! ret) {
#line 366
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"syntax error\n");
#line 367
    return (1);
  } else {

  }
#line 370
  if (root_structure) {
#line 371
    *root_structure = (json_val_t *)dom.root_structure;
  } else {

  }
#line 374
  json_parser_free(& parser);
#line 375
  close_filename(filename, input);
#line 376
  return (0);
}
}
#line 379 "jsonlint.c"
static int print_tree_iter(json_val_t *element , FILE *output ) 
{ int i ;

  {
#line 382
  if (! element) {
#line 383
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"error: no element in print tree\n");
#line 384
    return (-1);
  } else {

  }
#line 387
  switch (element->type) {
  case 2: 
#line 389
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"object begin (%d element)\n",
          element->length);
#line 390
  i = 0;
#line 390
  while (i < element->length) {
#line 391
    fprintf((FILE */* __restrict  */)output,
            (char const   */* __restrict  */)"key: %s\n",
            (*(element->u.object + i))->key);
#line 392
    print_tree_iter((*(element->u.object + i))->val, output);
#line 390
    i ++;
  }
#line 394
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"object end\n");
#line 395
  break;
  case 1: 
#line 397
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"array begin\n");
#line 398
  i = 0;
#line 398
  while (i < element->length) {
#line 399
    print_tree_iter(*(element->u.array + i), output);
#line 398
    i ++;
  }
#line 401
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"array end\n");
#line 402
  break;
  case 10: 
  case 9: 
  case 11: 
#line 406
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"constant\n");
#line 407
  break;
  case 5: 
#line 409
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"integer: %s\n", element->u.data);
#line 410
  break;
  case 7: 
#line 412
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"string: %s\n", element->u.data);
#line 413
  break;
  case 6: 
#line 415
  fprintf((FILE */* __restrict  */)output,
          (char const   */* __restrict  */)"float: %s\n", element->u.data);
#line 416
  break;
  default: ;
#line 418
  break;
  }
#line 420
  return (0);
}
}
#line 423 "jsonlint.c"
static int print_tree(json_val_t *root_structure , char *outputfile ) 
{ FILE *output ;

  {
#line 427
  output = open_filename((char const   *)outputfile, "a+", 0);
#line 428
  if (! output) {
#line 429
    return (2);
  } else {

  }
#line 430
  print_tree_iter(root_structure, output);
#line 431
  close_filename((char const   *)outputfile, output);
#line 432
  return (0);
}
}
#line 435 "jsonlint.c"
int usage(char const   *argv0 ) 
{ 

  {
#line 437
  printf((char const   */* __restrict  */)"usage: %s [options] JSON-FILE(s)...\n",
         argv0);
#line 438
  printf((char const   */* __restrict  */)"\t--no-comments : disallow C and YAML comments in json file (default to both on)\n");
#line 439
  printf((char const   */* __restrict  */)"\t--no-yaml-comments : disallow YAML comment (default to on)\n");
#line 440
  printf((char const   */* __restrict  */)"\t--no-c-comments : disallow C comment (default to on)\n");
#line 441
  printf((char const   */* __restrict  */)"\t--format : pretty print the json file to stdout (unless -o specified)\n");
#line 442
  printf((char const   */* __restrict  */)"\t--verify : quietly verified if the json file is valid. exit 0 if valid, 1 if not\n");
#line 443
  printf((char const   */* __restrict  */)"\t--max-nesting : limit the number of nesting in structure (default to no limit)\n");
#line 444
  printf((char const   */* __restrict  */)"\t--max-data : limit the number of characters of data (string/int/float) (default to no limit)\n");
#line 445
  printf((char const   */* __restrict  */)"\t--indent-string : set the string to use for indenting one level (default to 1 tab)\n");
#line 446
  printf((char const   */* __restrict  */)"\t--tree : build a tree (DOM)\n");
#line 447
  printf((char const   */* __restrict  */)"\t-o : output to a specific file instead of stdout\n");
#line 448
  exit(0);
}
}
#line 451 "jsonlint.c"
int main(int argc , char **argv ) 
{ int format ;
  int verify ;
  int use_tree ;
  int ret ;
  int i ;
  json_config config ;
  char *output ;
  int option_index ;
  struct option long_options[11] ;
  int c ;
  int tmp ;
  char const   *name ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  json_val_t *root_structure ;

  {
#line 453
  format = 0;
#line 453
  verify = 0;
#line 453
  use_tree = 0;
#line 454
  ret = 0;
#line 456
  output = (char *)"-";
#line 458
  memset((void *)(& config), 0, sizeof(json_config ));
#line 459
  config.max_nesting = 0U;
#line 460
  config.max_data = 0U;
#line 461
  config.allow_c_comments = 1;
#line 462
  config.allow_yaml_comments = 1;
#line 464
  while (1) {
#line 466
    long_options[0].name = "no-comments";
#line 466
    long_options[0].has_arg = 0;
#line 466
    long_options[0].flag = (int *)0;
#line 466
    long_options[0].val = 0;
#line 466
    long_options[1].name = "no-yaml-comments";
#line 466
    long_options[1].has_arg = 0;
#line 466
    long_options[1].flag = (int *)0;
#line 466
    long_options[1].val = 0;
#line 466
    long_options[2].name = "no-c-comments";
#line 466
    long_options[2].has_arg = 0;
#line 466
    long_options[2].flag = (int *)0;
#line 466
    long_options[2].val = 0;
#line 466
    long_options[3].name = "format";
#line 466
    long_options[3].has_arg = 0;
#line 466
    long_options[3].flag = (int *)0;
#line 466
    long_options[3].val = 0;
#line 466
    long_options[4].name = "verify";
#line 466
    long_options[4].has_arg = 0;
#line 466
    long_options[4].flag = (int *)0;
#line 466
    long_options[4].val = 0;
#line 466
    long_options[5].name = "help";
#line 466
    long_options[5].has_arg = 0;
#line 466
    long_options[5].flag = (int *)0;
#line 466
    long_options[5].val = 0;
#line 466
    long_options[6].name = "max-nesting";
#line 466
    long_options[6].has_arg = 1;
#line 466
    long_options[6].flag = (int *)0;
#line 466
    long_options[6].val = 0;
#line 466
    long_options[7].name = "max-data";
#line 466
    long_options[7].has_arg = 1;
#line 466
    long_options[7].flag = (int *)0;
#line 466
    long_options[7].val = 0;
#line 466
    long_options[8].name = "indent-string";
#line 466
    long_options[8].has_arg = 1;
#line 466
    long_options[8].flag = (int *)0;
#line 466
    long_options[8].val = 0;
#line 466
    long_options[9].name = "tree";
#line 466
    long_options[9].has_arg = 0;
#line 466
    long_options[9].flag = (int *)0;
#line 466
    long_options[9].val = 0;
#line 466
    long_options[10].name = (char const   *)0;
#line 466
    long_options[10].has_arg = 0;
#line 466
    long_options[10].flag = (int *)0;
#line 466
    long_options[10].val = 0;
#line 479
    tmp = getopt_long(argc, (char * const  *)argv, "o:",
                      (struct option  const  *)(long_options), & option_index);
#line 479
    c = tmp;
#line 480
    if (c == -1) {
#line 481
      break;
    } else {

    }
#line 482
    switch (c) {
    case 0: 
#line 484
    name = long_options[option_index].name;
#line 485
    tmp___11 = strcmp(name, "help");
#line 485
    if (tmp___11 == 0) {
#line 486
      usage((char const   *)*(argv + 0));
    } else {
#line 487
      tmp___10 = strcmp(name, "no-c-comments");
#line 487
      if (tmp___10 == 0) {
#line 488
        config.allow_c_comments = 0;
      } else {
#line 489
        tmp___9 = strcmp(name, "no-yaml-comments");
#line 489
        if (tmp___9 == 0) {
#line 490
          config.allow_yaml_comments = 0;
        } else {
#line 491
          tmp___8 = strcmp(name, "no-comments");
#line 491
          if (tmp___8 == 0) {
#line 492
            config.allow_yaml_comments = 0;
#line 492
            config.allow_c_comments = config.allow_yaml_comments;
          } else {
#line 493
            tmp___7 = strcmp(name, "format");
#line 493
            if (tmp___7 == 0) {
#line 494
              format = 1;
            } else {
#line 495
              tmp___6 = strcmp(name, "verify");
#line 495
              if (tmp___6 == 0) {
#line 496
                verify = 1;
              } else {
#line 497
                tmp___5 = strcmp(name, "max-nesting");
#line 497
                if (tmp___5 == 0) {
#line 498
                  tmp___0 = atoi((char const   *)optarg);
#line 498
                  config.max_nesting = (unsigned int )tmp___0;
                } else {
#line 499
                  tmp___4 = strcmp(name, "max-data");
#line 499
                  if (tmp___4 == 0) {
#line 500
                    tmp___1 = atoi((char const   *)optarg);
#line 500
                    config.max_data = (unsigned int )tmp___1;
                  } else {
#line 501
                    tmp___3 = strcmp(name, "indent-string");
#line 501
                    if (tmp___3 == 0) {
#line 502
                      indent_string = strdup((char const   *)optarg);
                    } else {
#line 503
                      tmp___2 = strcmp(name, "tree");
#line 503
                      if (tmp___2 == 0) {
#line 504
                        use_tree = 1;
                      } else {

                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
#line 505
    break;
    case 111: 
#line 508
    output = strdup((char const   *)optarg);
#line 509
    break;
    default: ;
#line 511
    break;
    }
  }
#line 514
  if (config.max_nesting < 0U) {
#line 515
    config.max_nesting = 0U;
  } else {

  }
#line 516
  if (! output) {
#line 517
    output = (char *)"-";
  } else {

  }
#line 518
  if (optind >= argc) {
#line 519
    usage((char const   *)*(argv + 0));
  } else {

  }
#line 521
  i = optind;
#line 521
  while (i < argc) {
#line 522
    if (use_tree) {
#line 524
      ret = do_tree(& config, (char const   *)*(argv + i), & root_structure);
#line 525
      if (ret) {
#line 526
        exit(ret);
      } else {

      }
#line 527
      print_tree(root_structure, output);
    } else {
#line 529
      if (format) {
#line 530
        ret = do_format(& config, (char const   *)*(argv + i),
                        (char const   *)output);
      } else {
#line 531
        if (verify) {
#line 532
          ret = do_verify(& config, (char const   *)*(argv + i));
        } else {
#line 534
          ret = do_parse(& config, (char const   *)*(argv + i));
        }
      }
    }
#line 536
    if (ret) {
#line 537
      exit(ret);
    } else {

    }
#line 521
    i ++;
  }
#line 539
  return (ret);
}
}
#line 1 "json.o"
/* #pragma merger(0,"/tmp/cil-mkv59NCk.i","-Wall,-Os,-fPIC") */
#line 242 "/usr/include/string.h"
extern  __attribute__((__nothrow__)) size_t strlen(char const   *__s )  __attribute__((__pure__,
__nonnull__(1))) ;
#line 139 "json.h"
int json_parser_char(json_parser *parser , unsigned char ch ) ;
#line 155
int json_print_raw(json_printer *printer , int type , char const   *data ,
                   uint32_t length ) ;
#line 162
int json_print_args(json_printer *printer ,
                    int (*f)(json_printer * , int  ,
                             char const   * , uint32_t  )  , ...) ;
#line 202
int json_parser_dom_free(json_parser_dom *dom ) ;
#line 58 "json.c"
static uint8_t character_class[128]  = 
#line 58 "json.c"
  {      (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)2,      (unsigned char)1,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)2,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)254,      (unsigned char)254,      (unsigned char)254,      (unsigned char)254, 
        (unsigned char)0,      (unsigned char)31,      (unsigned char)9,      (unsigned char)33, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)32,      (unsigned char)12, 
        (unsigned char)8,      (unsigned char)13,      (unsigned char)14,      (unsigned char)11, 
        (unsigned char)15,      (unsigned char)16,      (unsigned char)16,      (unsigned char)16, 
        (unsigned char)16,      (unsigned char)16,      (unsigned char)16,      (unsigned char)16, 
        (unsigned char)16,      (unsigned char)16,      (unsigned char)7,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)29,      (unsigned char)29,      (unsigned char)29, 
        (unsigned char)29,      (unsigned char)30,      (unsigned char)29,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)5, 
        (unsigned char)10,      (unsigned char)6,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)17,      (unsigned char)18,      (unsigned char)19, 
        (unsigned char)20,      (unsigned char)21,      (unsigned char)22,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)23,      (unsigned char)31,      (unsigned char)24,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)25,      (unsigned char)26, 
        (unsigned char)27,      (unsigned char)28,      (unsigned char)31,      (unsigned char)31, 
        (unsigned char)31,      (unsigned char)31,      (unsigned char)31,      (unsigned char)3, 
        (unsigned char)31,      (unsigned char)4,      (unsigned char)31,      (unsigned char)31};
#line 81 "json.c"
static char *character_escape[36]  = 
#line 81
  {      (char *)"\\u0000",      (char *)"\\u0001",      (char *)"\\u0002",      (char *)"\\u0003", 
        (char *)"\\u0004",      (char *)"\\u0005",      (char *)"\\u0006",      (char *)"\\u0007", 
        (char *)"\\b",      (char *)"\\t",      (char *)"\\n",      (char *)"\\u000b", 
        (char *)"\\f",      (char *)"\\r",      (char *)"\\u000e",      (char *)"\\u000f", 
        (char *)"\\u0010",      (char *)"\\u0011",      (char *)"\\u0012",      (char *)"\\u0013", 
        (char *)"\\u0014",      (char *)"\\u0015",      (char *)"\\u0016",      (char *)"\\u0017", 
        (char *)"\\u0018",      (char *)"\\u0019",      (char *)"\\u001a",      (char *)"\\u001b", 
        (char *)"\\u001c",      (char *)"\\u001d",      (char *)"\\u001e",      (char *)"\\u001f", 
        (char *)" ",      (char *)"!",      (char *)"\\\"",      (char *)"#"};
#line 157 "json.c"
static uint8_t const   state_transition_table[37][34]  = 
#line 157
  { {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )132, 
            (unsigned char const   )255,        (unsigned char const   )130,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )129,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )2,        (unsigned char const   )2,        (unsigned char const   )2,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )3,        (unsigned char const   )3,        (unsigned char const   )3,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )4,        (unsigned char const   )4,        (unsigned char const   )4,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )128, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )5,        (unsigned char const   )5,        (unsigned char const   )5,        (unsigned char const   )132, 
            (unsigned char const   )255,        (unsigned char const   )130,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )143,        (unsigned char const   )255,        (unsigned char const   )144, 
            (unsigned char const   )145,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )24,        (unsigned char const   )255, 
            (unsigned char const   )28,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )21, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )6,        (unsigned char const   )6,        (unsigned char const   )6,        (unsigned char const   )132, 
            (unsigned char const   )255,        (unsigned char const   )130,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )143,        (unsigned char const   )255,        (unsigned char const   )144, 
            (unsigned char const   )145,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )24,        (unsigned char const   )255, 
            (unsigned char const   )28,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )21, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )142,        (unsigned char const   )8,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )7,        (unsigned char const   )7}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )7, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )7,        (unsigned char const   )255, 
            (unsigned char const   )7,        (unsigned char const   )7,        (unsigned char const   )255,        (unsigned char const   )7, 
            (unsigned char const   )9,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )10, 
            (unsigned char const   )10,        (unsigned char const   )10,        (unsigned char const   )10,        (unsigned char const   )10, 
            (unsigned char const   )10,        (unsigned char const   )10,        (unsigned char const   )10,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )10,        (unsigned char const   )10,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )11, 
            (unsigned char const   )11,        (unsigned char const   )11,        (unsigned char const   )11,        (unsigned char const   )11, 
            (unsigned char const   )11,        (unsigned char const   )11,        (unsigned char const   )11,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )11,        (unsigned char const   )11,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )12, 
            (unsigned char const   )12,        (unsigned char const   )12,        (unsigned char const   )12,        (unsigned char const   )12, 
            (unsigned char const   )12,        (unsigned char const   )12,        (unsigned char const   )12,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )12,        (unsigned char const   )12,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )146, 
            (unsigned char const   )146,        (unsigned char const   )146,        (unsigned char const   )146,        (unsigned char const   )146, 
            (unsigned char const   )146,        (unsigned char const   )146,        (unsigned char const   )146,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )146,        (unsigned char const   )146,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )14, 
            (unsigned char const   )15,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )129,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )141,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )129,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )141,        (unsigned char const   )15, 
            (unsigned char const   )15,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )140,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )140,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )17, 
            (unsigned char const   )17,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )129,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )134, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )17, 
            (unsigned char const   )17,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )18,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )18,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )135}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )19,        (unsigned char const   )19,        (unsigned char const   )255,        (unsigned char const   )20, 
            (unsigned char const   )20,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )20, 
            (unsigned char const   )20,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )255, 
            (unsigned char const   )133,        (unsigned char const   )255,        (unsigned char const   )131,        (unsigned char const   )255, 
            (unsigned char const   )129,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )20, 
            (unsigned char const   )20,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )22,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )23,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )138,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )25,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )26, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )27,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )137,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )29,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )30, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )139, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )32,        (unsigned char const   )255}, 
   {        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )33,        (unsigned char const   )32}, 
   {        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )136, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32,        (unsigned char const   )32, 
            (unsigned char const   )33,        (unsigned char const   )32}, 
   {        (unsigned char const   )34,        (unsigned char const   )136,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34,        (unsigned char const   )34, 
            (unsigned char const   )34,        (unsigned char const   )34}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )36,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}, 
   {        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )9,        (unsigned char const   )255,        (unsigned char const   )255,        (unsigned char const   )255, 
            (unsigned char const   )255,        (unsigned char const   )255}};
#line 206 "json.c"
static uint8_t const   buffer_policy_table[37][34]  = 
#line 206
  { {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )2,        (unsigned char const   )2,        (unsigned char const   )2, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )2,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )2,        (unsigned char const   )0, 
            (unsigned char const   )2,        (unsigned char const   )2,        (unsigned char const   )0,        (unsigned char const   )2, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )1,        (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )1, 
            (unsigned char const   )1,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}, 
   {        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0,        (unsigned char const   )0, 
            (unsigned char const   )0,        (unsigned char const   )0}};
#line 255 "json.c"
__inline static void *memory_realloc(void *(*realloc_fct)(void * , size_t  ) ,
                                     void *ptr , size_t size ) 
{ void *tmp___1 ;

  {
#line 257
  if (realloc_fct) {
#line 257
    tmp___1 = (*realloc_fct)(ptr, size);
  } else {
#line 257
    tmp___1 = realloc(ptr, size);
  }
#line 257
  return (tmp___1);
}
}
#line 260 "json.c"
__inline static void *memory_calloc(void *(*calloc_fct)(size_t  , size_t  ) ,
                                    size_t nmemb , size_t size ) 
{ void *tmp___1 ;

  {
#line 262
  if (calloc_fct) {
#line 262
    tmp___1 = (*calloc_fct)(nmemb, size);
  } else {
#line 262
    tmp___1 = calloc(nmemb, size);
  }
#line 262
  return (tmp___1);
}
}
#line 268 "json.c"
static int state_grow(json_parser *parser ) 
{ uint32_t newsize ;
  void *ptr ;

  {
#line 270
  newsize = parser->stack_size * 2U;
#line 273
  if (parser->config.max_nesting != 0U) {
#line 274
    return (5);
  } else {

  }
#line 276
  ptr = memory_realloc(parser->config.user_realloc, (void *)parser->stack,
                       (unsigned long )newsize * sizeof(uint8_t ));
#line 277
  if (! ptr) {
#line 278
    return (1);
  } else {

  }
#line 279
  parser->stack = (uint8_t *)ptr;
#line 280
  parser->stack_size = newsize;
#line 281
  return (0);
}
}
#line 284 "json.c"
static int state_push(json_parser *parser , int mode ) 
{ int ret ;
  int tmp ;
  uint32_t tmp___0 ;

  {
#line 286
  if (parser->stack_offset >= parser->stack_size) {
#line 287
    tmp = state_grow(parser);
#line 287
    ret = tmp;
#line 288
    if (ret) {
#line 289
      return (ret);
    } else {

    }
  } else {

  }
#line 291
  tmp___0 = parser->stack_offset;
#line 291
  (parser->stack_offset) ++;
#line 291
  *(parser->stack + tmp___0) = (unsigned char )mode;
#line 292
  return (0);
}
}
#line 295 "json.c"
static int state_pop(json_parser *parser , int mode ) 
{ 

  {
#line 297
  if (parser->stack_offset == 0U) {
#line 298
    return (3);
  } else {

  }
#line 299
  (parser->stack_offset) --;
#line 300
  if ((int )*(parser->stack + parser->stack_offset) != mode) {
#line 301
    return (4);
  } else {

  }
#line 302
  return (0);
}
}
#line 305 "json.c"
static int buffer_grow(json_parser *parser ) 
{ uint32_t newsize ;
  void *ptr ;
  int max ;

  {
#line 309
  max = (int )parser->config.max_data;
#line 311
  if (max > 0) {
#line 311
    if (parser->buffer_size == (unsigned int )max) {
#line 312
      return (6);
    } else {

    }
  } else {

  }
#line 313
  newsize = parser->buffer_size * 2U;
#line 314
  if (max > 0) {
#line 314
    if (newsize > (unsigned int )max) {
#line 315
      newsize = (unsigned int )max;
    } else {

    }
  } else {

  }
#line 317
  ptr = memory_realloc(parser->config.user_realloc, (void *)parser->buffer,
                       (unsigned long )newsize * sizeof(char ));
#line 318
  if (! ptr) {
#line 319
    return (1);
  } else {

  }
#line 320
  parser->buffer = (char *)ptr;
#line 321
  parser->buffer_size = newsize;
#line 322
  return (0);
}
}
#line 325 "json.c"
static int buffer_push(json_parser *parser , unsigned char c ) 
{ int ret ;
  uint32_t tmp ;

  {
#line 329
  if (parser->buffer_offset + 1U >= parser->buffer_size) {
#line 330
    ret = buffer_grow(parser);
#line 331
    if (ret) {
#line 332
      return (ret);
    } else {

    }
  } else {

  }
#line 334
  tmp = parser->buffer_offset;
#line 334
  (parser->buffer_offset) ++;
#line 334
  *(parser->buffer + tmp) = (char )c;
#line 335
  return (0);
}
}
#line 338 "json.c"
static int do_callback_withbuf(json_parser *parser , int type ) 
{ int tmp ;

  {
#line 340
  if (! parser->callback) {
#line 341
    return (0);
  } else {

  }
#line 342
  *(parser->buffer + parser->buffer_offset) = (char )'\000';
#line 343
  tmp = (*(parser->callback))(parser->userdata, type,
                              (char const   *)parser->buffer,
                              parser->buffer_offset);
#line 343
  return (tmp);
}
}
#line 346 "json.c"
static int do_callback(json_parser *parser , int type ) 
{ int tmp ;

  {
#line 348
  if (! parser->callback) {
#line 349
    return (0);
  } else {

  }
#line 350
  tmp = (*(parser->callback))(parser->userdata, type,
                              (char const   *)((void *)0), 0U);
#line 350
  return (tmp);
}
}
#line 353 "json.c"
static int do_buffer(json_parser *parser ) 
{ int ret ;

  {
#line 355
  ret = 0;
#line 357
  switch ((int )parser->type) {
  case 8: 
  case 7: 
  case 6: 
  case 5: 
  case 11: 
  case 9: 
  case 10: 
#line 361
  ret = do_callback_withbuf(parser, (int )parser->type);
#line 362
  if (ret) {
#line 363
    return (ret);
  } else {

  }
#line 364
  break;
  default: ;
#line 366
  break;
  }
#line 368
  parser->buffer_offset = 0U;
#line 369
  return (ret);
}
}
#line 372 "json.c"
static uint8_t const   hextable[128]  = 
#line 372
  {      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )0,      (unsigned char const   )1,      (unsigned char const   )2,      (unsigned char const   )3, 
        (unsigned char const   )4,      (unsigned char const   )5,      (unsigned char const   )6,      (unsigned char const   )7, 
        (unsigned char const   )8,      (unsigned char const   )9,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )10,      (unsigned char const   )11,      (unsigned char const   )12, 
        (unsigned char const   )13,      (unsigned char const   )14,      (unsigned char const   )15,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )10,      (unsigned char const   )11,      (unsigned char const   )12, 
        (unsigned char const   )13,      (unsigned char const   )14,      (unsigned char const   )15,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1, 
        (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1,      (unsigned char const   )-1};
#line 391 "json.c"
static int decode_unicode_char(json_parser *parser ) 
{ uint32_t uval ;
  char *b ;
  int offset ;
  uint32_t tmp ;
  uint32_t tmp___0 ;
  uint32_t tmp___1 ;
  uint32_t tmp___2 ;
  uint32_t tmp___3 ;
  uint32_t tmp___4 ;
  uint32_t tmp___5 ;
  uint32_t tmp___6 ;
  uint32_t tmp___7 ;
  uint32_t tmp___8 ;

  {
#line 394
  b = parser->buffer;
#line 395
  offset = (int )parser->buffer_offset;
#line 397
  uval = (unsigned int )(((((int const   )hextable[(unsigned char )*(b + (offset - 4))] << 12) | ((int const   )hextable[(unsigned char )*(b + (offset - 3))] << 8)) | ((int const   )hextable[(unsigned char )*(b + (offset - 2))] << 4)) | (int const   )hextable[(unsigned char )*(b + (offset - 1))]);
#line 400
  parser->buffer_offset -= 4U;
#line 403
  if (! parser->unicode_multi) {
#line 403
    if (uval < 128U) {
#line 404
      tmp = parser->buffer_offset;
#line 404
      (parser->buffer_offset) ++;
#line 404
      *(b + tmp) = (char )uval;
#line 405
      return (0);
    } else {

    }
  } else {

  }
#line 408
  if (parser->unicode_multi) {
#line 409
    if (! ((uval & 64512U) == 56320U)) {
#line 410
      return (9);
    } else {

    }
#line 412
    uval = (unsigned int )(65536 + (((int )parser->unicode_multi & 1023) << 10)) + (uval & 1023U);
#line 413
    tmp___0 = parser->buffer_offset;
#line 413
    (parser->buffer_offset) ++;
#line 413
    *(b + tmp___0) = (char )((uval >> 18) | 240U);
#line 414
    tmp___1 = parser->buffer_offset;
#line 414
    (parser->buffer_offset) ++;
#line 414
    *(b + tmp___1) = (char )(((uval >> 12) & 63U) | 128U);
#line 415
    tmp___2 = parser->buffer_offset;
#line 415
    (parser->buffer_offset) ++;
#line 415
    *(b + tmp___2) = (char )(((uval >> 6) & 63U) | 128U);
#line 416
    tmp___3 = parser->buffer_offset;
#line 416
    (parser->buffer_offset) ++;
#line 416
    *(b + tmp___3) = (char )((uval & 63U) | 128U);
#line 417
    parser->unicode_multi = (unsigned short)0;
#line 418
    return (0);
  } else {

  }
#line 421
  if ((uval & 64512U) == 56320U) {
#line 422
    return (10);
  } else {

  }
#line 423
  if ((uval & 64512U) == 55296U) {
#line 424
    parser->unicode_multi = (unsigned short )uval;
#line 425
    return (0);
  } else {

  }
#line 428
  if (uval < 2048U) {
#line 429
    tmp___4 = parser->buffer_offset;
#line 429
    (parser->buffer_offset) ++;
#line 429
    *(b + tmp___4) = (char )((uval >> 6) | 192U);
#line 430
    tmp___5 = parser->buffer_offset;
#line 430
    (parser->buffer_offset) ++;
#line 430
    *(b + tmp___5) = (char )((uval & 63U) | 128U);
  } else {
#line 432
    tmp___6 = parser->buffer_offset;
#line 432
    (parser->buffer_offset) ++;
#line 432
    *(b + tmp___6) = (char )((uval >> 12) | 224U);
#line 433
    tmp___7 = parser->buffer_offset;
#line 433
    (parser->buffer_offset) ++;
#line 433
    *(b + tmp___7) = (char )(((uval >> 6) & 63U) | 128U);
#line 434
    tmp___8 = parser->buffer_offset;
#line 434
    (parser->buffer_offset) ++;
#line 434
    *(b + tmp___8) = (char )((uval & 63U) | 128U);
  }
#line 436
  return (0);
}
}
#line 439 "json.c"
static int buffer_push_escape(json_parser *parser , unsigned char next ) 
{ char c ;
  int tmp ;

  {
#line 441
  c = (char )'\000';
#line 443
  switch ((int )next) {
  case 98: 
#line 444
  c = (char )'\b';
#line 444
  break;
  case 102: 
#line 445
  c = (char )'\f';
#line 445
  break;
  case 110: 
#line 446
  c = (char )'\n';
#line 446
  break;
  case 114: 
#line 447
  c = (char )'\r';
#line 447
  break;
  case 116: 
#line 448
  c = (char )'\t';
#line 448
  break;
  case 34: 
#line 449
  c = (char )'\"';
#line 449
  break;
  case 47: 
#line 450
  c = (char )'/';
#line 450
  break;
  case 92: 
#line 451
  c = (char )'\\';
#line 451
  break;
  }
#line 454
  tmp = buffer_push(parser, (unsigned char )c);
#line 454
  return (tmp);
}
}
#line 459 "json.c"
int act_uc(json_parser *parser ) 
{ int ret ;

  {
#line 462
  ret = decode_unicode_char(parser);
#line 462
  if (ret) {
#line 462
    return (ret);
  } else {

  }
#line 463
  if (parser->unicode_multi) {
#line 463
    parser->state = (unsigned char)35;
  } else {
#line 463
    parser->state = (unsigned char)7;
  }
#line 464
  return (0);
}
}
#line 467 "json.c"
int act_yb(json_parser *parser ) 
{ 

  {
#line 469
  if (! parser->config.allow_yaml_comments) {
#line 470
    return (7);
  } else {

  }
#line 471
  parser->save_state = parser->state;
#line 472
  return (0);
}
}
#line 475 "json.c"
int act_cb(json_parser *parser ) 
{ 

  {
#line 477
  if (! parser->config.allow_c_comments) {
#line 478
    return (7);
  } else {

  }
#line 479
  parser->save_state = parser->state;
#line 480
  return (0);
}
}
#line 483 "json.c"
int act_ce(json_parser *parser ) 
{ 

  {
#line 485
  if ((int )parser->save_state > 6) {
#line 485
    parser->state = (unsigned char)1;
  } else {
#line 485
    parser->state = parser->save_state;
  }
#line 486
  return (0);
}
}
#line 489 "json.c"
int act_ob(json_parser *parser ) 
{ int ret ;

  {
#line 492
  ret = do_callback(parser, 2);
#line 492
  if (ret) {
#line 492
    return (ret);
  } else {

  }
#line 493
  ret = state_push(parser, 1);
#line 493
  if (ret) {
#line 493
    return (ret);
  } else {

  }
#line 494
  parser->expecting_key = (unsigned char)1;
#line 495
  return (0);
}
}
#line 498 "json.c"
int act_oe(json_parser *parser ) 
{ int ret ;

  {
#line 501
  ret = do_callback(parser, 4);
#line 501
  if (ret) {
#line 501
    return (ret);
  } else {

  }
#line 502
  ret = state_pop(parser, 1);
#line 502
  if (ret) {
#line 502
    return (ret);
  } else {

  }
#line 503
  parser->expecting_key = (unsigned char)0;
#line 504
  return (0);
}
}
#line 507 "json.c"
int act_ab(json_parser *parser ) 
{ int ret ;

  {
#line 510
  ret = do_callback(parser, 1);
#line 510
  if (ret) {
#line 510
    return (ret);
  } else {

  }
#line 511
  ret = state_push(parser, 0);
#line 511
  if (ret) {
#line 511
    return (ret);
  } else {

  }
#line 512
  return (0);
}
}
#line 514 "json.c"
int act_ae(json_parser *parser ) 
{ int ret ;

  {
#line 517
  ret = do_callback(parser, 3);
#line 517
  if (ret) {
#line 517
    return (ret);
  } else {

  }
#line 518
  ret = state_pop(parser, 0);
#line 518
  if (ret) {
#line 518
    return (ret);
  } else {

  }
#line 519
  return (0);
}
}
#line 522 "json.c"
int act_se(json_parser *parser ) 
{ int ret ;
  int tmp ;

  {
#line 525
  if (parser->expecting_key) {
#line 525
    tmp = 8;
  } else {
#line 525
    tmp = 7;
  }
#line 525
  ret = do_callback_withbuf(parser, tmp);
#line 525
  if (ret) {
#line 525
    return (ret);
  } else {

  }
#line 526
  parser->buffer_offset = 0U;
#line 527
  if (parser->expecting_key) {
#line 527
    parser->state = (unsigned char)4;
  } else {
#line 527
    parser->state = (unsigned char)1;
  }
#line 528
  parser->expecting_key = (unsigned char)0;
#line 529
  return (0);
}
}
#line 532 "json.c"
int act_sp(json_parser *parser ) 
{ 

  {
#line 534
  if (parser->stack_offset == 0U) {
#line 535
    return (11);
  } else {

  }
#line 536
  if ((int )*(parser->stack + (parser->stack_offset - 1U)) == 1) {
#line 537
    parser->expecting_key = (unsigned char)1;
#line 538
    parser->state = (unsigned char)3;
  } else {
#line 540
    parser->state = (unsigned char)5;
  }
#line 541
  return (0);
}
}
#line 552 "json.c"
static struct action_descr actions_map[19]  = 
#line 552
  {      {(int (*)(json_parser *parser ))((void *)0), (unsigned char)0,
      (unsigned char)5, (unsigned char)0}, 
        {& act_sp, (unsigned char)0, (unsigned char)0, (unsigned char)1}, 
        {& act_ab, (unsigned char)0, (unsigned char)6, (unsigned char)0}, 
        {& act_ae, (unsigned char)0, (unsigned char)1, (unsigned char)1}, 
        {& act_ob, (unsigned char)0, (unsigned char)2, (unsigned char)0}, 
        {& act_oe, (unsigned char)0, (unsigned char)1, (unsigned char)1}, 
        {& act_cb, (unsigned char)0, (unsigned char)31, (unsigned char)1}, 
        {& act_yb, (unsigned char)0, (unsigned char)34, (unsigned char)1}, 
        {& act_ce, (unsigned char)0, (unsigned char)0, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)10,
      (unsigned char)1, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)9,
      (unsigned char)1, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)11,
      (unsigned char)1, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)6,
      (unsigned char)18, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)6,
      (unsigned char)16, (unsigned char)0}, 
        {& act_se, (unsigned char)0, (unsigned char)0, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)5,
      (unsigned char)13, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)5,
      (unsigned char)14, (unsigned char)0}, 
        {(int (*)(json_parser *parser ))((void *)0), (unsigned char)5,
      (unsigned char)15, (unsigned char)0}, 
        {& act_uc, (unsigned char)0, (unsigned char)0, (unsigned char)0}};
#line 574 "json.c"
static int do_action(json_parser *parser , int next_state ) 
{ struct action_descr *descr ;
  int ret ;

  {
#line 576
  descr = & actions_map[next_state & -129];
#line 579
  if (descr->call) {
#line 580
    if (descr->dobuffer) {
#line 581
      ret = do_buffer(parser);
#line 581
      if (ret) {
#line 581
        return (ret);
      } else {

      }
    } else {

    }
#line 582
    ret = (*(descr->call))(parser);
#line 582
    if (ret) {
#line 582
      return (ret);
    } else {

    }
  } else {

  }
#line 584
  if (descr->state) {
#line 585
    parser->state = descr->state;
  } else {

  }
#line 586
  parser->type = (enum __anonenum_json_type_26 )descr->type;
#line 587
  return (ret);
}
}
#line 594 "json.c"
int json_parser_init(json_parser *parser , json_config *config ,
                     int (*callback)(void *userdata , int type ,
                                     char const   *data , uint32_t length ) ,
                     void *userdata ) 
{ void *tmp ;
  void *tmp___0 ;

  {
#line 597
  memset((void *)parser, 0, sizeof(*parser));
#line 599
  if (config) {
#line 600
    memcpy((void */* __restrict  */)(& parser->config),
           (void const   */* __restrict  */)config, sizeof(json_config ));
  } else {

  }
#line 601
  parser->callback = callback;
#line 602
  parser->userdata = userdata;
#line 605
  parser->stack_offset = 0U;
#line 606
  parser->state = (unsigned char)0;
#line 609
  if (parser->config.max_nesting > 0U) {
#line 609
    parser->stack_size = parser->config.max_nesting;
  } else {
#line 609
    parser->stack_size = 256U;
  }
#line 613
  tmp = memory_calloc(parser->config.user_calloc,
                      (unsigned long )parser->stack_size,
                      sizeof(*(parser->stack + 0)));
#line 613
  parser->stack = (uint8_t *)tmp;
#line 614
  if (! parser->stack) {
#line 615
    return (1);
  } else {

  }
#line 618
  if (parser->config.buffer_initial_size > 0U) {
#line 618
    parser->buffer_size = parser->config.buffer_initial_size;
  } else {
#line 618
    parser->buffer_size = 4096U;
  }
#line 622
  if (parser->config.max_data > 0U) {
#line 622
    if (parser->buffer_size > parser->config.max_data) {
#line 623
      parser->buffer_size = parser->config.max_data;
    } else {

    }
  } else {

  }
#line 625
  tmp___0 = memory_calloc(parser->config.user_calloc,
                          (unsigned long )parser->buffer_size, sizeof(char ));
#line 625
  parser->buffer = (char *)tmp___0;
#line 626
  if (! parser->buffer) {
#line 627
    free((void *)parser->stack);
#line 628
    return (1);
  } else {

  }
#line 630
  return (0);
}
}
#line 634 "json.c"
int json_parser_free(json_parser *parser ) 
{ 

  {
#line 636
  if (! parser) {
#line 637
    return (0);
  } else {

  }
#line 638
  free((void *)parser->stack);
#line 639
  free((void *)parser->buffer);
#line 640
  parser->stack = (uint8_t *)((void *)0);
#line 641
  parser->buffer = (char *)((void *)0);
#line 642
  return (0);
}
}
#line 646 "json.c"
int json_parser_is_done(json_parser *parser ) 
{ int tmp ;

  {
#line 649
  if (parser->stack_offset == 0U) {
#line 649
    if ((int )parser->state != 0) {
#line 649
      tmp = 1;
    } else {
#line 649
      tmp = 0;
    }
  } else {
#line 649
    tmp = 0;
  }
#line 649
  return (tmp);
}
}
#line 656 "json.c"
int json_parser_string(json_parser *parser , char const   *s , uint32_t length ,
                       uint32_t *processed ) 
{ int ret ;
  int next_class ;
  int next_state ;
  int buffer_policy ;
  uint32_t i ;
  unsigned char ch ;

  {
#line 664
  ret = 0;
#line 665
  i = 0U;
#line 665
  while (i < length) {
#line 666
    ch = (unsigned char )*(s + i);
#line 668
    ret = 0;
#line 669
    if ((int )ch >= 128) {
#line 669
      next_class = 31;
    } else {
#line 669
      next_class = (int )character_class[ch];
    }
#line 670
    if (next_class == 254) {
#line 671
      ret = 2;
#line 672
      break;
    } else {

    }
#line 675
    next_state = (int )state_transition_table[parser->state][next_class];
#line 676
    buffer_policy = (int )buffer_policy_table[parser->state][next_class];
#line 679
    if (next_state == 255) {
#line 680
      ret = 8;
#line 681
      break;
    } else {

    }
#line 685
    if (buffer_policy) {
#line 686
      if (buffer_policy == 2) {
#line 686
        ret = buffer_push_escape(parser, ch);
      } else {
#line 686
        ret = buffer_push(parser, ch);
      }
#line 689
      if (ret) {
#line 690
        break;
      } else {

      }
    } else {

    }
#line 694
    if (next_state & 128) {
#line 695
      ret = do_action(parser, next_state);
    } else {
#line 697
      parser->state = (unsigned char )next_state;
    }
#line 698
    if (ret) {
#line 699
      break;
    } else {

    }
#line 665
    i ++;
  }
#line 701
  if (processed) {
#line 702
    *processed = i;
  } else {

  }
#line 703
  return (ret);
}
}
#line 708 "json.c"
int json_parser_char(json_parser *parser , unsigned char ch ) 
{ int tmp ;

  {
#line 710
  tmp = json_parser_string(parser, (char const   *)((char *)(& ch)), 1U,
                           (uint32_t *)((void *)0));
#line 710
  return (tmp);
}
}
#line 714 "json.c"
int json_print_init(json_printer *printer ,
                    int (*callback)(void *userdata , char const   *s ,
                                    uint32_t length ) , void *userdata ) 
{ 

  {
#line 716
  memset((void *)printer, '\000', sizeof(*printer));
#line 717
  printer->callback = callback;
#line 718
  printer->userdata = userdata;
#line 720
  printer->indentstr = (char *)"\t";
#line 721
  printer->indentlevel = 0;
#line 722
  printer->enter_object = 1;
#line 723
  printer->first = 1;
#line 724
  return (0);
}
}
#line 729 "json.c"
int json_print_free(json_printer *printer ) 
{ 

  {
#line 731
  return (0);
}
}
#line 736 "json.c"
static int print_string(json_printer *printer , char const   *data ,
                        uint32_t length ) 
{ int i ;
  unsigned char c ;
  char *esc ;
  size_t tmp ;

  {
#line 740
  (*(printer->callback))(printer->userdata, "\"", 1U);
#line 741
  i = 0;
#line 741
  while ((unsigned int )i < length) {
#line 742
    c = (unsigned char )*(data + i);
#line 743
    if ((int )c < 36) {
#line 744
      esc = character_escape[c];
#line 745
      tmp = strlen((char const   *)esc);
#line 745
      (*(printer->callback))(printer->userdata, (char const   *)esc,
                             (unsigned int )tmp);
    } else {
#line 746
      if ((int )c == 92) {
#line 747
        (*(printer->callback))(printer->userdata, "\\\\", 2U);
      } else {
#line 749
        (*(printer->callback))(printer->userdata, data + i, 1U);
      }
    }
#line 741
    i ++;
  }
#line 751
  (*(printer->callback))(printer->userdata, "\"", 1U);
#line 752
  return (0);
}
}
#line 755 "json.c"
static int print_indent(json_printer *printer ) 
{ int i ;
  size_t tmp ;

  {
#line 758
  (*(printer->callback))(printer->userdata, "\n", 1U);
#line 759
  i = 0;
#line 759
  while (i < printer->indentlevel) {
#line 760
    tmp = strlen((char const   *)printer->indentstr);
#line 760
    (*(printer->callback))(printer->userdata,
                           (char const   *)printer->indentstr,
                           (unsigned int )tmp);
#line 759
    i ++;
  }
#line 761
  return (0);
}
}
#line 764 "json.c"
int json_print_mode(json_printer *printer , int type , char const   *data ,
                    uint32_t length , int pretty ) 
{ int enterobj ;
  char const   *tmp ;
  int tmp___0 ;

  {
#line 766
  enterobj = printer->enter_object;
#line 768
  if (! enterobj) {
#line 768
    if (! printer->afterkey) {
#line 768
      if (type != 3) {
#line 768
        if (type != 4) {
#line 769
          (*(printer->callback))(printer->userdata, ",", 1U);
#line 770
          if (pretty) {
#line 770
            print_indent(printer);
          } else {

          }
        } else {

        }
      } else {

      }
    } else {

    }
  } else {

  }
#line 773
  if (pretty) {
#line 773
    if (enterobj) {
#line 773
      if (! printer->first) {
#line 773
        if (type != 3) {
#line 773
          if (type != 4) {
#line 774
            print_indent(printer);
          } else {

          }
        } else {

        }
      } else {

      }
    } else {

    }
  } else {

  }
#line 777
  printer->first = 0;
#line 778
  printer->enter_object = 0;
#line 779
  printer->afterkey = 0;
#line 780
  switch (type) {
  case 1: 
#line 782
  (*(printer->callback))(printer->userdata, "[", 1U);
#line 783
  (printer->indentlevel) ++;
#line 784
  printer->enter_object = 1;
#line 785
  break;
  case 2: 
#line 787
  (*(printer->callback))(printer->userdata, "{", 1U);
#line 788
  (printer->indentlevel) ++;
#line 789
  printer->enter_object = 1;
#line 790
  break;
  case 3: 
  case 4: 
#line 793
  (printer->indentlevel) --;
#line 794
  if (pretty) {
#line 794
    if (! enterobj) {
#line 794
      print_indent(printer);
    } else {

    }
  } else {

  }
#line 795
  if (type == 4) {
#line 795
    tmp = "}";
  } else {
#line 795
    tmp = "]";
  }
#line 795
  (*(printer->callback))(printer->userdata, tmp, 1U);
#line 796
  break;
  case 5: 
#line 797
  (*(printer->callback))(printer->userdata, data, length);
#line 797
  break;
  case 6: 
#line 798
  (*(printer->callback))(printer->userdata, data, length);
#line 798
  break;
  case 11: 
#line 799
  (*(printer->callback))(printer->userdata, "null", 4U);
#line 799
  break;
  case 9: 
#line 800
  (*(printer->callback))(printer->userdata, "true", 4U);
#line 800
  break;
  case 10: 
#line 801
  (*(printer->callback))(printer->userdata, "false", 5U);
#line 801
  break;
  case 8: 
#line 803
  print_string(printer, data, length);
#line 804
  if (pretty) {
#line 804
    tmp___0 = 2;
  } else {
#line 804
    tmp___0 = 1;
  }
#line 804
  (*(printer->callback))(printer->userdata, ": ", (unsigned int )tmp___0);
#line 805
  printer->afterkey = 1;
#line 806
  break;
  case 7: 
#line 808
  print_string(printer, data, length);
#line 809
  break;
  default: ;
#line 811
  break;
  }
#line 814
  return (0);
}
}
#line 818 "json.c"
int json_print_pretty(json_printer *printer , int type , char const   *data ,
                      uint32_t length ) 
{ int tmp ;

  {
#line 820
  tmp = json_print_mode(printer, type, data, length, 1);
#line 820
  return (tmp);
}
}
#line 824 "json.c"
int json_print_raw(json_printer *printer , int type , char const   *data ,
                   uint32_t length ) 
{ int tmp ;

  {
#line 826
  tmp = json_print_mode(printer, type, data, length, 0);
#line 826
  return (tmp);
}
}
#line 830 "json.c"
int json_print_args(json_printer *printer ,
                    int (*f)(json_printer * , int  ,
                             char const   * , uint32_t  )  , ...) 
{ va_list ap ;
  char *data ;
  uint32_t length ;
  int type ;
  int ret ;
  size_t tmp ;

  {
#line 839
  ret = 0;
#line 840
  __builtin_va_start(ap, f);
#line 841
  while (1) {
#line 841
    type = __builtin_va_arg(ap, int );
#line 841
    if (! (type != -1)) {
#line 841
      break;
    } else {

    }
#line 842
    switch (type) {
    case 1: 
    case 3: 
    case 2: 
    case 4: 
    case 11: 
    case 9: 
    case 10: 
#line 850
    ret = (*f)(printer, type, (char const   *)((void *)0), 0U);
#line 851
    break;
    case 5: 
    case 6: 
    case 8: 
    case 7: 
#line 856
    data = __builtin_va_arg(ap, char *);
#line 857
    length = __builtin_va_arg(ap, uint32_t );
#line 858
    if (length == 4294967295U) {
#line 859
      tmp = strlen((char const   *)data);
#line 859
      length = (unsigned int )tmp;
    } else {

    }
#line 860
    ret = (*f)(printer, type, (char const   *)data, length);
#line 861
    break;
    }
#line 863
    if (ret) {
#line 864
      break;
    } else {

    }
  }
#line 866
  __builtin_va_end(ap);
#line 867
  return (ret);
}
}
#line 870 "json.c"
static int dom_push(struct json_parser_dom *ctx , void *val ) 
{ void *ptr ;
  uint32_t newsize ;

  {
#line 872
  if (ctx->stack_offset == ctx->stack_size) {
#line 874
    newsize = ctx->stack_size * 2U;
#line 875
    ptr = memory_realloc(ctx->user_realloc, (void *)ctx->stack,
                         (unsigned long )newsize);
#line 876
    if (! ptr) {
#line 877
      return (1);
    } else {

    }
#line 878
    ctx->stack = (struct stack_elem *)ptr;
#line 879
    ctx->stack_size = newsize;
  } else {

  }
#line 881
  (ctx->stack + ctx->stack_offset)->val = val;
#line 882
  (ctx->stack + ctx->stack_offset)->key = (char *)((void *)0);
#line 883
  (ctx->stack + ctx->stack_offset)->key_length = 0U;
#line 884
  (ctx->stack_offset) ++;
#line 885
  return (0);
}
}
#line 888 "json.c"
static int dom_pop(struct json_parser_dom *ctx , void **val ) 
{ 

  {
#line 890
  (ctx->stack_offset) --;
#line 891
  *val = (ctx->stack + ctx->stack_offset)->val;
#line 892
  return (0);
}
}
#line 895 "json.c"
int json_parser_dom_init(json_parser_dom *dom ,
                         void *(*create_structure)(int  , int  ) ,
                         void *(*create_data)(int  , char const   * , uint32_t  ) ,
                         int (*append)(void * , char * , uint32_t  , void * ) ) 
{ void *tmp ;

  {
#line 900
  memset((void *)dom, 0, sizeof(*dom));
#line 901
  dom->stack_size = 1024U;
#line 902
  dom->stack_offset = 0U;
#line 903
  tmp = memory_calloc(dom->user_calloc, (unsigned long )dom->stack_size,
                      sizeof(*(dom->stack)));
#line 903
  dom->stack = (struct stack_elem *)tmp;
#line 904
  if (! dom->stack) {
#line 905
    return (1);
  } else {

  }
#line 906
  dom->append = append;
#line 907
  dom->create_structure = create_structure;
#line 908
  dom->create_data = create_data;
#line 909
  return (0);
}
}
#line 912 "json.c"
int json_parser_dom_free(json_parser_dom *dom ) 
{ 

  {
#line 914
  free((void *)dom->stack);
#line 915
  return (0);
}
}
#line 918 "json.c"
int json_parser_dom_callback(void *userdata , int type , char const   *data ,
                             uint32_t length ) 
{ struct json_parser_dom *ctx ;
  void *v ;
  struct stack_elem *stack ;
  void *tmp ;

  {
#line 920
  ctx = (struct json_parser_dom *)userdata;
#line 922
  stack = (struct stack_elem *)((void *)0);
#line 924
  switch (type) {
  case 1: 
  case 2: 
#line 927
  v = (*(ctx->create_structure))((int )ctx->stack_offset, type == 2);
#line 928
  if (! v) {
#line 929
    return (12);
  } else {

  }
#line 930
  dom_push(ctx, v);
#line 931
  break;
  case 4: 
  case 3: 
#line 934
  dom_pop(ctx, & v);
#line 935
  if (ctx->stack_offset > 0U) {
#line 936
    stack = ctx->stack + (ctx->stack_offset - 1U);
#line 937
    (*(ctx->append))(stack->val, stack->key, stack->key_length, v);
#line 938
    free((void *)stack->key);
  } else {
#line 940
    ctx->root_structure = v;
  }
#line 941
  break;
  case 8: 
#line 943
  stack = ctx->stack + (ctx->stack_offset - 1U);
#line 944
  tmp = memory_calloc(ctx->user_calloc, (unsigned long )(length + 1U),
                      sizeof(char ));
#line 944
  stack->key = (char *)tmp;
#line 945
  stack->key_length = length;
#line 946
  if (! stack->key) {
#line 947
    return (1);
  } else {

  }
#line 948
  memcpy((void */* __restrict  */)stack->key,
         (void const   */* __restrict  */)data, (unsigned long )length);
#line 949
  break;
  case 7: 
  case 5: 
  case 6: 
  case 11: 
  case 9: 
  case 10: 
#line 956
  stack = ctx->stack + (ctx->stack_offset - 1U);
#line 957
  v = (*(ctx->create_data))(type, data, length);
#line 958
  (*(ctx->append))(stack->val, stack->key, stack->key_length, v);
#line 959
  free((void *)stack->key);
#line 960
  break;
  }
#line 962
  return (0);
}
}