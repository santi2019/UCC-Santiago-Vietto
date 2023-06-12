package edu.ucc.arqSoft.service.model;

import java.util.List;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.PeliculaDao;
import edu.ucc.arqSoft.service.dao.SocioDao;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = { "classpath:test-context.xml", "classpath:/spring/applicationContext.xml" })
@Transactional
public class PeliculaTest {

	@Autowired
    private PeliculaDao peliculaDao;

    @Test
    public void testFindAll()
    {
        
    	List<Pelicula> peliculas = peliculaDao.getAll();
    	
    	Assert.assertEquals(0, peliculas.size());
     }
}
