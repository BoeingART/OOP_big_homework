// #include "chessdisplay.h"
// #include "ctime"

// void chessDisplay::display( char chessName ) {
//     int timer = clock();
//     system( "clear" );
//     struct winsize size;
//     ioctl( STDIN_FILENO, TIOCGWINSZ, &size );
//     int up_down_space = ( size.ws_row - 11 ) / 2;
//     int left_right_space = ( size.ws_col - 21 ) / 2;
//     enter_print( up_down_space );
//     space_print( left_right_space );
//     printf( "┏━━━━┳━━━━┳━━━━┳━━━━┓" );
//     space_print( left_right_space );
//     printf( "\n" );
//     int CC = 0, ZF = 0, ZY = 0, GY = 0, MC = 0, HZ = 0;
//     for ( int i = 0; i < chessControl::row; i++ ) {
//         space_print( left_right_space );
//         printf( "┃" );
//         for ( int j = 0; j < chessControl::line; j++ ) {
//             if ( chessControl::chessBoard[ j ][ i ].occ ) {
//                 if ( chessControl::chessBoard[ j ][ i ].name == 'c' ) {
//                     if ( chessName == 'c' )
//                         printf( "\033[1;31m" );
//                     else
//                         printf( "\033[31m" );
//                     switch ( CC ) {
//                     case 0:
//                         printf( " 曹 " );
//                         break;
//                     case 1:
//                         printf( " 曹 " );
//                         break;
//                     case 2:
//                         printf( " 操 " );
//                         break;
//                     case 3:
//                         printf( " 操 " );
//                         break;
//                     default:
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     CC++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'f' ) {
//                     if ( chessName == 'f' )
//                         printf( "\033[1;32m" );
//                     else
//                         printf( "\033[32m" );
//                     switch ( ZF ) {
//                     case 0:
//                         printf( " 张 " );
//                         break;
//                     case 1:
//                         printf( " 飞 " );
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     ZF++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'm' ) {
//                     if ( chessName == 'm' )
//                         printf( "\033[1;33m" );
//                     else
//                         printf( "\033[33m" );
//                     switch ( MC ) {
//                     case 0:
//                         printf( " 马 " );
//                         break;
//                     case 1:
//                         printf( " 超 " );
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     MC++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'g' ) {
//                     if ( chessName == 'g' )
//                         printf( "\033[1;34m" );
//                     else
//                         printf( "\033[34m" );
//                     switch ( GY ) {
//                     case 0:
//                         printf( " 关 " );
//                         break;
//                     case 1:
//                         printf( " 羽 " );
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     GY++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'h' ) {
//                     if ( chessName == 'h' )
//                         printf( "\033[1;35m" );
//                     else
//                         printf( "\033[35m" );
//                     switch ( HZ ) {
//                     case 0:
//                         printf( " 黄 " );
//                         break;
//                     case 1:
//                         printf( " 忠 " );
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     HZ++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'y' ) {
//                     if ( chessName == 'y' )
//                         printf( "\033[1;36m" );
//                     else
//                         printf( "\033[36m" );
//                     switch ( ZY ) {
//                     case 0:
//                         printf( " 赵 " );
//                         break;
//                     case 1:
//                         printf( " 云 " );
//                         break;
//                     }
//                     printf( "\033[0m" );
//                     ZY++;
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == '1' ) {
//                     if ( chessName == '1' )
//                         printf( "\033[1;37m" );
//                     else
//                         printf( "\033[37m" );
//                     printf( " 兵 " );
//                     printf( "\033[0m" );
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == '2' ) {
//                     if ( chessName == '2' )
//                         printf( "\033[1;37m" );
//                     else
//                         printf( "\033[37m" );
//                     printf( " 兵 " );
//                     printf( "\033[0m" );
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == '3' ) {
//                     if ( chessName == '3' )
//                         printf( "\033[1;37m" );
//                     else
//                         printf( "\033[37m" );
//                     printf( " 兵 " );
//                     printf( "\033[0m" );
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == '4' ) {
//                     if ( chessName == '4' )
//                         printf( "\033[1;37m" );
//                     else
//                         printf( "\033[37m" );
//                     printf( " 兵 " );
//                     printf( "\033[0m" );
//                 }
//             } else {
//                 if ( chessControl::chessBoard[ j ][ i ].name == 'p' ) {
//                     if ( chessName == 'p' )
//                         printf( "\033[1;30m ██ \033[0m" );
//                     else
//                         printf( "\033[1;30m    \033[0m" );
//                 } else if ( chessControl::chessBoard[ j ][ i ].name == 'q' ) {
//                     if ( chessName == 'q' )
//                         printf( "\033[1;30m ██ \033[0m" );
//                     else
//                         printf( "\033[1;30m    \033[0m" );
//                 }
//             }
//             printf( "┃" );
//         }
//         space_print( left_right_space );
//         printf( "\n" );
//         if ( i != chessControl::row - 1 ) {
//             space_print( left_right_space );
//             printf( "┣━━━━╋━━━━╋━━━━╋━━━━┫" );
//             space_print( left_right_space );
//             printf( "\n" );
//         } else {
//             space_print( left_right_space );
//             printf( "┗━━━━┻━━━━┻━━━━┻━━━━┛" );
//             space_print( left_right_space );
//             printf( "\n" );
//         }
//     }
//     int timer_ = clock();
//     printf( "%d\n", timer_ - timer );
// }

// void chessDisplay::space_print( int number ) {
//     for ( int i = 0; i < number; i++ ) {
//         printf( " " );
//     }
// }

// void chessDisplay::enter_print( int number ) {
//     for ( int i = 0; i < number; i++ ) {
//         printf( "\n" );
//     }
// }