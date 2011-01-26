<?php defined('SYSPATH') or die('No direct script access.');

class Controller_Website extends Controller_Template {

	public function before() {
		$parent_ret = parent::before();
		
		$this->template->title = "{Diwant Vaidya}";
		$this->template->mission = "Awesome!";
		$this->template->stylesheets = array(
			'media/css/reset.css',
			'media/css/smoothness/jquery-ui-1.8.6.custom.css',
			'media/css/core.css',
		);
		$this->template->javascripts = array(
			'media/js/jquery-1.4.2.min.js',
			'media/js/jquery-ui-1.8.6.custom.min.js',
		);
		$this->template->meta_description = 'Online portfolio of front-end web-developer Diwant Vaidya. See sites I have completed, read about my skills, learn about my services and rates.';
		$this->template->meta_keywords = 'diwant, vaidya, diwant vaidya, web developer, front-end developer, front-end, css, html, xhtml, js, javascript, jquery, portfolio, blog, php, mvc, version control, svn, database, mysql, fbjs, fbml, facebook mark-up language, facebook javascript, facebook connect, cms, ajax, xml-rpc';
		$this->template->site_logo = Url::site('media/images/pp_logo.png');
		return $parent_ret;
	}
	public function after(){
		$parent_ret = parent::after();
		if( empty($this->template->title_head) ){
			$this->template->title_head = $this->template->title;
		}
		return $parent_ret;
	}
}

