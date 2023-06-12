package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Sensor;

@Repository
public class SensorImpDao extends GenericDaoImp<Sensor, Long> implements SensorDao{

}
