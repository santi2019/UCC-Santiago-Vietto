package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;
import edu.ucc.arqSoft.service.common.dao.GenericDao;
import edu.ucc.arqSoft.service.model.Sensor;

@Repository
public interface SensorDao extends GenericDao<Sensor, Long>{

}
