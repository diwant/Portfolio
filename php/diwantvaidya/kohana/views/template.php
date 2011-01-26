<?php
/**
 * Template for all pages
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
	<!-- Title -->
	<title><?php if(Helper_Utility::isDebugMode()):?>[d]<?php endif;?><?php print $title_head;?></title>
	
	<!-- SEO -->
	<meta name="description" content="<?php print $meta_description;?>" />
	<meta name="keywords" content="<?php print $meta_keywords;?>" />
	<meta name="author" content="Diwant Vaidya">
	<meta name="robots" content="index, follow">
	<meta http-equiv="content-type" content="text/html;charset=UTF-8" />
	
	<!-- Title -->
	<title>Online Portfolio of Front-End Web Developer, Diwant Vaidya</title>
	
	<!-- Favicon -->
	<link rel="shortcut icon" href="<?php print URL::site('media/images/diwant-favicon.png');?>" type="image/x-icon"/>
	<link rel="apple-touch-icon" href="<?php print URL::site('media/images/diwant-favicon.png');?>" type="image/x-icon"/>
	
	<!-- Stylesheets -->
	<?php foreach($stylesheets as $stylesheet):?>
		<?php print HTML::style("$stylesheet");?>
	<?php endforeach;?>
	<!--[if IE]>
		<?php print HTML::style('media/css/core/iefix.css');?>
	<![endif]-->
	
	<!-- Javascripts -->
	<?php foreach($javascripts as $javascript):?>
		<?php print HTML::script("$javascript");?>
	<?php endforeach;?>
	<?php if( !Helper_Utility::isDebugMode() ):?>
	<script type="text/javascript">

	  var _gaq = _gaq || [];
	  _gaq.push(['_setAccount', 'UA-954812-11']);
	  _gaq.push(['_trackPageview']);

	  (function() {
		var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
		ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
		var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
	  })();

	</script>
	<?php endif;?>
</head>
<body>
<!--[if lte IE 7]>
	<div id="iewarning">
		<div>Upgrade your Internet Explorer to 8+ for a nicer experience.</div>
		<div class="followup">We do not support Internet Explorer 7 and below.  <a href="mailto:support@paradigmpop.com">Let us know</a> if this is a major issue for you.</div>
	</div>
<![endif]-->	
<div id="page" class="clear-block"><div id="page-inner">
	<div id="contactMe">
		<ul>
			<li><a href="mailto:diwant@gmail.com">diwant@gmail.com</a></li>
			<li>(217) 697-0070</li>
			<li>Chicago, IL</li>
		</ul>
	</div>
	<div id="header" class="wrap"><div id="header-inner"  class="clear-block wrap-inner">
		<div id="logo-title">
			<div id="site-title">
				<?php if(!empty($title)):?><h1 class="title"><?php print $title; ?></h1><?php endif;?>
			</div>
			<div id="mission">
				<?php print $mission;?>
			</div>
		</div>
		<!-- /#logo-title -->
		<div id="header-blocks" class="region region-header"></div>
		<!-- /#header-blocks -->
	</div></div>
	<!-- /#header-inner, /#header -->
	<div id="main" class="wrap"><div id="main-inner" class="clear-block wrap-inner">
		<div id="content"><div id="content-inner">
			<div id="content-header" class="clear-block">
				<!-- breadcrumb goes here -->
				<div id="messages">
					<?php
						// output messages
						$messages = Helper_Message::readAllMessages();
						if(!empty($messages)) {
							foreach($messages as $type => $messages) {
								$style_code = "";
								if( $type == "debug" and !Helper_Utility::isDebugMode() ){
									$style_code = "style='display:none;'";
								}
								foreach($messages as $message) {
									
									echo '<div class="message '.$type.'" '.$style_code.'>'.$message.'</div>';
								}
							}
						}
					?>
				</div>
			</div>
			<!-- /#content-header -->
			<div id="content-area" class="clear-block">
				<?php print $content;?>
			</div>
		</div></div>
		<!-- /#content-inner, /#content -->
	</div></div>
	<!-- /#main-inner, /#main -->
	<div id="footer" class="wrap"><div id="footer-inner" class="region region-footer clear-block wrap-inner">
		<div class="block">
			<p>(c) 2010 Diwant Vaidya.  I know <a href="<?php print Route::url('resume',array('flavor'=>'java'));?>">Java</a>, <a href="<?php print Route::url('resume',array('flavor'=>'c'));?>">C++</a>, and <a href="<?php print Route::url('resume',array('flavor'=>'web'));?>">web development</a>.</p>
		</div>
	</div></div>
	<!-- /#footer-inner, /#footer -->
</div></div>
<!-- /#page-inner, /#page -->
<?php if(Helper_Utility::isDebugMode()):?>
	<div id="debug">
		<h1>Debug Print out</h1>
		<p>You can only see this if the system is running in debug mode (detected by which server it is running on).</p>
		<h2>Kohana</h2>
		<p>Environment is <?php print Kohana::$environment;?></p>
		<h2>Request</h2>
		<div><?php print Kohana::debug($_REQUEST);?></div>
		<h3>POST</h3>
		<?php print Kohana::debug($_POST);?>
		<h3>GET</h3>
		<?php print Kohana::debug($_GET);?>
		<h2>FILES</h2>
		<?php print Kohana::debug($_FILES);?>
		<h2>Server</h2>
		<?php print Kohana::debug($_SERVER);?>
	</div>
<?php endif;?>
</body>
</html>
