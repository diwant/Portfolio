<?php defined('SYSPATH') or die('No Direct Script Access');

class Controller_Resume extends Controller_Website {
	function action_read() {
		$resume = new View('resume');
		$flavor = $this->request->param('flavor');
		$this->template->title = "Diwant Vaidya";
		$this->template->mission = new View("mission/$flavor");
		$resume->pieces = array();
		$resume->familiarities = array('Eclipse', 'Notepad++','Amazon S3', 'Cloud Services','Ubuntu Server','Apache Web Server','Adobe Creative Suite');
		switch($flavor){
			case 'web':
				$this->template->title_head = "Diwant Vaidya, Seven Years Experience in Web Development";
				$resume->pieces = $this->pieces_web();
				$resume->familiarities = array_merge($resume->familiarities, array('Facebook','Subversion', 'Joomla', 'AJAX','XML-RPC'));
				break;
			case 'c':
				$this->template->title_head = "Diwant Vaidya, Five Years Experience in C/C++ Development";
				$resume->pieces = $this->pieces_c();
				$resume->familiarities = array_merge($resume->familiarities, array('MinGW','GCC', 'Visual Studio', 'SDL','TCP/UDP Networking', 'OGRE 3D'));
				break;
			case 'java':
				$this->template->title_head = "Diwant Vaidya, Five Years Experience in Java Development";
				$resume->pieces = $this->pieces_java();
				$resume->familiarities = array_merge($resume->familiarities, array('Eclipse Plugin Framework', 'JBoss Server'));
				break;				
			default:
				break;
		}
		$skillset = array();
		foreach($resume->pieces as $piece){
			$skillset = array_merge($skillset, $piece['skills']);
		}
		foreach($resume->pieces as &$piece){
			$piece['skills_safe'] = array();
			foreach($piece['skills'] as $skill){
				$piece['skills_safe'][] = str_replace(array(' ','+'),'_',$skill);
			}
		}
		$skillset = array_unique($skillset);
		sort($skillset);
		$resume->skillset = $skillset;
		$resume->familiarities = array_unique(array_merge($skillset, $resume->familiarities));
		sort($resume->familiarities);
		$resume->cover = new View("cover/$flavor");
		$branding = new View("branding/$flavor");
		$this->template->content = $branding.$resume;
	}
	private function pieces_web(){
		return array(
			array(
				"title"=>"Paradigm PoP", 
				"caption"=>"A technology startup company's website.  Has a full strength blog, product listing, and contact page.", 
				"screen"=>Url::site('media/images/screens/paradigmpop.png'),
				"link"=>"http://www.paradigmpop.com",
				"skills"=>array('Drupal','PHP','HTML','CSS', 'MySQL'),
			),
			array(
				"title"=>"My PoP Project", 
				"caption"=>"A web based project management tool, used by more than 250 teams running more than 290 projects.", 
				"screen"=>Url::site('media/images/screens/mypopproject-tool.png'),
				"link"=>"http://www.mypopproject.com",
				"skills"=>array('Kohana','PHP','HTML','CSS', 'jQuery','MySQL'),
			),
			array(
				"title"=>"Boulder First", 
				"caption"=>"A web and SEO consultancy company's website.  Initially developed on PHP, the entire site now runs on Google Sites for easy updating.", 
				"screen"=>Url::site('media/images/screens/boulderfirst.png'),
				"link"=>"http://www.boulderfirst.com",
				"skills"=>array('Google Sites','HTML','CSS'),
			),
			array(
				"title"=>"Compete Globally Now", 
				"caption"=>"A tutoring company's website, built very closely to original specifications.", 
				"screen"=>Url::site('media/images/screens/competegloballynow.png'),
				"link"=>"http://www.competegloballynow.com",
				"skills"=>array('PHP','HTML','CSS'),
			),
			array(
				"title"=>"Death To Kalia", 
				"caption"=>"An SEO and social optimized content management system and blog set up for an independent entertainment content provider.", 
				"screen"=>Url::site('media/images/screens/deathtokalia.png'),
				"link"=>"http://www.deathtokalia.com",
				"skills"=>array('Drupal','PHP','HTML','CSS', 'MySQL'),
			),
			array(
				"title"=>"PoP Circle", 
				"caption"=>"A personal and professional network manager used to engineer and maintain a specific distance in relationships with friends and colleagues.", 
				"screen"=>Url::site('media/images/screens/mypopcircle.png'),
				"link"=>"http://www.mypopcircle.com",
				"skills"=>array('Drupal','PHP','HTML','CSS','MySQL'),
			),
		);
	}
	private function pieces_c(){
		return array(
			array(
				"title"=>"Temple of Blocs", 
				"caption"=>"A three dimensional video game written in C++ using the OGRE3D rendering framework.", 
				"screen"=>Url::site('media/images/screens/templeofblocs.png'),
				"link"=>"http://video.google.com/videoplay?docid=4352393027466241957&hl=en",
				"skills"=>array('Eclipse', 'C++','OO','OGRE3D','Gang of Four'),
			),
			array(
				"title"=>"How to Make Games With C++", 
				"caption"=>"Instructed a Digital Media Arts summer camp on developing video games using C++.  Students learned C++ as well as OO and game development principles.", 
				"screen"=>Url::site('media/images/screens/dma-team.png'),
				"link"=>"http://www.digitalmediaacademy.org/teens-kids-camp/teen-summer-camps/teen-computer-courses-summer-camps/game-programming-with-c/",
				"skills"=>array('C++','Eclipse','SDL','OO'),
			),
		);
	}
	private function pieces_java(){
		return array(
			array(
				"title"=>"PoP Project", 
				"caption"=>"Originally this site was in Struts 2 and JSP with EJB 3 on Hibernate. This tool was developed with a strong focus on clean MVC architecture.", 
				"screen"=>Url::site('media/images/screens/mypopproject-tool.png'),
				"link"=>"http://www.mypopproject.com",
				"skills"=>array('JBoss', 'Struts 2', 'EJB 3','Hibernate', 'MySQL','FreeMarker'),
			),
			array(
				"title"=>"PoP Circle", 
				"caption"=>"When initially prototyped, PoP Circle was a written on the JBoss Seam framework with JSF and EJB3", 
				"screen"=>Url::site('media/images/screens/mypopcircle.png'),
				"link"=>"http://www.mypopcircle.com",
				"skills"=>array('JBoss', 'Seam', 'JSF', 'EJB 3', 'Hibernate', 'MySQL'),
			),
		);
	}
}
