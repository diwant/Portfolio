<?php 
/**
 * Pulls together portfolio, skills list, etc.
 */
?>
<script type="text/javascript">
<!--
	$(document).ready(function(){
		$("#skillset a").click(function(){
			$("#skillset a").addClass("disabled");
			$(this).removeClass("disabled");
			var skill = $(this).children(".skill").html();
			skill = skill.replace(/\s/g,'_');
			skill = skill.replace(/\+/g,'_');
			$(".piece").css({"opacity":0.2});
			$("."+skill).css({"opacity":1});
			return false;
		});
	});
-->
</script>
<div id="skillset">
	<?php foreach($skillset as $skill):?><a href="#"><span class="skill"><?php print $skill;?></span></a>&nbsp;<?php endforeach;?>
</div>
<div id="portfolio">
	<?php foreach($pieces as $piece):?>
		<div class="piece <?php print implode(' ',$piece['skills_safe']);?>">
			<span class="screen">
				<a href="<?php print $piece['link'];?>"><img src="<?php print $piece['screen'];?>" alt="<?php print $piece['title'];?>"/></a>
			</span>
			<span class="title">
				<a href="<?php print $piece['link'];?>"><?php print $piece['title'];?></a>
			</span>
			<span class="caption">
				<?php print $piece['caption'];?>
			</span>
			<span class="skills">
				<?php print implode(', ',$piece['skills']);?>
			</span> 
		</div>
	<?php endforeach;?>
</div>
<div id="familiarities">
	<h2>I Have Used:</h2>
	<ul>
		<?php foreach($familiarities as $familiar):?>
			<li><?php print $familiar;?></li>
		<?php endforeach;?>
	</ul>	
</div>
<div id="cover">
	<h2>Hello my name is Diwant,</h2>
	<img class="profilePic" src="http://www.gravatar.com/avatar/ab5604b6e388a595fd5595f2d6790c9a?s=64" alt="@diwant"/>
	<div class="text">
		<?php print $cover;?>
		<p>I offer my services on a freelance or contract basis. I am based in Chicago, which means that for contracts in Chicago I am available to work on-site. For contracts out of Chicago I decide to telecommunicate or fly in on a per-contract basis.
		<div class="banana" style="margin-top:20px;"><span><a href="mailto:diwant@gmail.com">Contact me</a></span></div>
	</div>
</div>
