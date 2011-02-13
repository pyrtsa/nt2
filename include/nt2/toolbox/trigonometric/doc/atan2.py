[ ##script manually modified
{
    'functor' : {       ## intrinsics values related to functor atan2
        'arity'         : '2',    ## functor number of parameters
        'ret_arity'     : '0',## must be '0' or omitted if not a tuple
        'types'         : ['real_', 'unsigned_int_', 'signed_int_'],     ## list of types string
##        'simd_types'    : ['real_convert_'], 
        'rturn'         : { 'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type' },     ## ditionary of return types
        'call_types'    : [],## types used in call ['T']*arity if omitted 
        'type_defs'     : [],  ## supplementary typedefs
        }, ## end of functor
    'unit'    : {       ## informations for creating unit tests
        'global_header' : { ## header of machin.cpp
            'first_stamp' : 'created  by $author$ the $date$', ## creation stamp
            'stamp'       : 'modified by $author$ the $date$', ## modification stamp
            'included'    : ['#include <nt2/toolbox/trigonometric/include/constants.hpp>',
                             '#include <nt2/toolbox/libc/include/atan2.hpp>'],     ## list of supplementary include directives
            'notes'       : [],        ## list of strings that will be included in a
                                            ## global comment
            },
        'specific_values' : {
                'real_'       : {
                    'nt2::Inf<T>()'  :  {'result' : 'nt2::Nan<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::Minf<T>()' :  {'result' : 'nt2::Nan<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::Nan<T>()'  :  {'result' : 'nt2::Nan<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::One<T>()'  :  {'result' : 'nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                    'nt2::Half<T>()' :  {'result' : 'nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                    'nt2::Mone<T>()' :  {'result' : '-3*nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                    'nt2::Mhalf<T>()':  {'result' : '-3*nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                    'nt2::Zero<T>()' :  {'result' : 'nt2::Zero<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::Inf<T>(),nt2::One<T>()'  :  {'result' : 'nt2::Pio_2<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::Minf<T>(),nt2::One<T>()' :  {'result' : '-nt2::Pio_2<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::One<T>(),nt2::Inf<T>()'  :  {'result' : 'nt2::Zero<r_t>()',  'ulp_thresh':'0.5'},
                    'nt2::One<T>(),nt2::Minf<T>()' :  {'result' : 'nt2::Pi<r_t>()',  'ulp_thresh':'0.5'},
                 },
                'signed_int_   ': {
                    'nt2::Zero<T>()' :  {'result' : 'nt2::Zero<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::One<T>()'  :  {'result' : 'nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                    'nt2::Mone<T>()' :  {'result' : '-3*nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                },
                'default': {
                    'nt2::Zero<T>()':   {'result' : 'nt2::Zero<r_t>()', 'ulp_thresh':'0.5'},
                    'nt2::One<T>()' :   {'result' : 'nt2::Pi<r_t>()/4', 'ulp_thresh':'0.5'},
                },
           },  ## dictionary of parameters and values to be tested
        'ranges'          :  {
            'default'       : [["nt2::Zero<T>()","nt2::One<T>()"],["nt2::Zero<T>()","nt2::One<T>()"]],
            'real_'         : [["nt2::Mone<T>()","nt2::One<T>()"],["nt2::Mone<T>()","nt2::One<T>()"]],
            'signed_int_'   : [["T(-1)","T(1)"],["T(-1)","T(1)"]],
            },  ## dictionary of ranges for random tests
        'verif_test'      : { ## verification dictionary
            'simd'          : {'real_convert_' : 'real_'},    
            'property_call'   : {'real_' : ['nt2::atan2(a0,a1)'],},  ## dictionary of calls per types
            'property_value'  : {'real_' : ['nt2::libc::atan2(a0,a1)'],}, ## dictionary of alternate calls
            'ulp_thresh'      : {'real_' : '0.5',},     ## validity thresholds(s)
        },  ## end of verif_test
    },  ## end of unit 
},
]