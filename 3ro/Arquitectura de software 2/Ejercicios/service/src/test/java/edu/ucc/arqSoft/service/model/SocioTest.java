package edu.ucc.arqSoft.service.model;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.SocioDao;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = { "classpath:test-context.xml", "classpath:/spring/applicationContext.xml" })
@Transactional
public class SocioTest {
	
	@Autowired
    private SocioDao socioDao;

    @Test
    public void testFindById()
    {
        Socio socio = socioDao.load(1L);

        Assert.assertEquals("Edu", socio.getNombre());
        Assert.assertEquals("Gaite", socio.getApellido());
        Assert.assertEquals("edu@gmail.com", socio.getEmail());
        Assert.assertEquals("11111111", socio.getDni());
    }

	
    @Test
    public void testInsert()
    {
    	Socio socio = new Socio();
    	socio.setNombre("Test");
    	socio.setApellido("Test");
    	socio.setDni("2222");
    	socio.setEmail("eee@gmail");
    	
    	socioDao.insert(socio);
    	
        Assert.assertEquals(2, socio.getId().longValue());
        
    }
	

}
