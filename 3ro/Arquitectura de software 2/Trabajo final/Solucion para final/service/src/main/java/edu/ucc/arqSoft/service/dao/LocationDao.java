package edu.ucc.arqSoft.service.dao;


import org.springframework.stereotype.Repository;
import edu.ucc.arqSoft.service.common.dao.GenericDao;
import edu.ucc.arqSoft.service.model.Location;

@Repository
public interface LocationDao extends GenericDao<Location, Long>{

}
