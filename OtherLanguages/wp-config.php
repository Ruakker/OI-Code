<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('WP_CACHE', true);
define( 'WPCACHEHOME', '/home/ftp/s/s8142269/wp-content/plugins/wp-super-cache/' );
define( 'DB_NAME', 's8142269' );
/** MySQL database username */
define( 'DB_USER', 's8142269' );
/** MySQL database password */
define( 'DB_PASSWORD', 'Chocola4everBest' );
/** MySQL hostname */
define( 'DB_HOST', 'localhost' );
/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );
/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );
/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         ': ZeQk!cLB_T!,*x~.f@QP}=MSH0,M9rL 6[qg&g,nj`1iYChg}+9u;>RZA2:F. ' );
define( 'SECURE_AUTH_KEY',  '[=W~s:|!  { 0c:yNmcz}-T#&[g-ww;T{i.B]mja1u;&v0X0hR91|[Qt<~7v.Iih' );
define( 'LOGGED_IN_KEY',    'ywNc4I)jot|7MU}>=q!:]w%4Hz#Kf^&R*MqKv*R*s|52YkO_2,zvv*I[y`?*ygvo' );
define( 'NONCE_KEY',        'kJC%);YRL}#eJ1cvS(vKoxJd1i#gSSGOg!FFRU1%T(Q,-XOS!T03]Ne{0e7uUDkz' );
define( 'AUTH_SALT',        'IZ[)#I.2nFmd:q/3b_ J(k;(EK8}Y:sMP*HNcy_6$KU])6mBwRuKVZ=Q12Is@@|A' );
define( 'SECURE_AUTH_SALT', 'MPWn]/G-9=a<yK.TXqjd0Dw`uDI8_L`jCP)4 %wBFU$)>]L[=.svsWxe-ry+&><x' );
define( 'LOGGED_IN_SALT',   't`/QSOKap:@fm`rs}6KD^o,UFGLMMR0,/Cu-7R7gdE*aaEJAA2O><H?E_*2NwN~D' );
define( 'NONCE_SALT',       'qXn%TGIxe0Ehc2=)W u!vv6V:/e`uK`h)gRL;C Dy!*0VnZP3d-9D<+5~uOyIcl0' );
define( 'WP_ALLOW_REPAIR', true );
/**#@-*/
/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';
/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );
/* That's all, stop editing! Happy publishing. */
/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';