<?php defined('SYSPATH') or die('No direct script access.');

class Helper_Utility {
	public static function isDebugMode() {
		return Kohana::$environment!=Kohana::PRODUCTION;
	}
	public static function get_rgba($hex,$alpha=1){
		return "rgba(".base_convert(substr($hex,0,2),16,10).",".base_convert(substr($hex,2,2),16,10).",".base_convert(substr($hex,4,2),16,10).",$alpha)";
	}
	/**
	* Make an active link of any links in a text
	* @param text text to do
	* @return string with all links in <a></a>
	*/
	public static function make_active_links($text){
		# this functions deserves credit to the fine folks at phpbb.com
		$text = preg_replace('#(script|about|applet|activex|chrome):#is', "\\1:", $text);

		// pad it with a space so we can match things at the start of the 1st line.
		$ret = ' ' . $text;

		// matches an "xxxx://yyyy" URL at the start of a line, or after a space.
		// xxxx can only be alpha characters.
		// yyyy is anything up to the first space, newline, comma, double quote or <
		$ret = preg_replace("#(^|[\n ])([\w]+?://[\w\#$%&~/.\-;:=,?@\[\]+]*)#is", "\\1<a href=\"\\2\" class=\"linkLink\" target=\"_blank\">\\2</a>", $ret);

		// matches a "www|ftp.xxxx.yyyy[/zzzz]" kinda lazy URL thing
		// Must contain at least 2 dots. xxxx contains either alphanum, or "-"
		// zzzz is optional.. will contain everything up to the first space, newline,
		// comma, double quote or <.
		$ret = preg_replace("#(^|[\n ])((www|ftp)\.[\w\#$%&~/.\-;:=,?@\[\]+]*)#is", "\\1<a href=\"http://\\2\" class=\"linkLink\" target=\"_blank\">\\2</a>", $ret);

		// matches an email@domain type address at the start of a line, or after a space.
		// Note: Only the followed chars are valid; alphanums, "-", "_" and or ".".
		$ret = preg_replace("#(^|[\n ])([a-z0-9&\-_.]+?)@([\w\-]+\.([\w\-\.]+\.)*[\w]+)#i", "\\1<a class=\"linkLink\" href=\"mailto:\\2@\\3\">\\2@\\3</a>", $ret);

		// Remove our padding..
		$ret = substr($ret, 1);
		return $ret;
	}
}
